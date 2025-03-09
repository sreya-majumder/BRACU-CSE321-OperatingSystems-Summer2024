#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
    int fd[2];
    pid_t parent_home,child_opr;
    char parent_buffer[100];
    char child_buffer[100];

    struct shared {
        char sel[100];
        int b;
    };

    int p = pipe(fd);
    if(p == -1){
        perror("pipe");
        exit(1);
    }


    parent_home = getpid();
    void *parent_shared_memory;
    int parent_shared_memory_id;

    parent_shared_memory_id = shmget((key_t)25, sizeof(struct shared), 0666 | IPC_CREAT);

    if (parent_shared_memory_id == -1) {
        perror("shmget");
        exit(1);
    }

    
    parent_shared_memory = shmat(parent_shared_memory_id, NULL, 0);
    if (parent_shared_memory == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    printf("Provide Your Input from Given Options:\n");
    printf("1. Type a to Add Money\n");
    printf("2. Type w to Withdraw Money\n");
    printf("3. Type c to Check Balance\n");
    scanf("%s", parent_buffer);
    
    struct shared *send_sm_data;
    send_sm_data = (struct shared*)parent_shared_memory;
    strcpy((*send_sm_data).sel,parent_buffer);
    (*send_sm_data).b = 1000;

    printf("Your selection: %s\n\n", (*send_sm_data).sel);

    child_opr = fork();
    if(child_opr < 0){
        perror("fork");
        exit(1);
    }
    else if(child_opr == 0){
        close(fd[0]);
        void *child_shared_memory;
        int child_shared_memory_id;

        child_shared_memory_id = shmget((key_t)25, sizeof(struct shared), 0666);
        child_shared_memory = shmat(child_shared_memory_id, NULL, 0);
        if (child_shared_memory == (void *)-1) {
            perror("shmat");
            exit(EXIT_FAILURE);
        }
        struct shared *receive_sm_data = (struct shared*)child_shared_memory;

        if(strcmp((*receive_sm_data).sel, "a") == 0){
            printf("Enter amount to be added: \n");
            scanf("%s",  child_buffer);
            int entered_amount = atoi(child_buffer);
            if(entered_amount > 0){
                (*receive_sm_data).b += entered_amount;
                printf("Balance added successfully\n");
                printf("Updated balance after addition:\n%d\n", (*receive_sm_data).b);
            }
            else{
                printf("Adding failed, Invalid amount\n");
            }
        }
        else if(strcmp((*receive_sm_data).sel, "w") == 0){
            printf("Enter amount to be withdrawn: \n");
            scanf("%s",child_buffer);
            int entered_amount = atoi(child_buffer);
            if(entered_amount > 0 && entered_amount <= (*receive_sm_data).b){
                (*receive_sm_data).b -= entered_amount;
                printf("Balance withdrawn successfully\n");
                printf("Updated balance after withdrawal:\n%d\n", (*receive_sm_data).b);
            }
            else{
                printf("Withdrawal failed, Invalid amount\n");
            }
        }
        else if(strcmp((*receive_sm_data).sel, "c") == 0){
            printf("Your current balance is:\n%d\n", (*receive_sm_data).b);
        }
        else{
            printf("Invalid selection\n");
        }

        write(fd[1], "Thank you for using", strlen("Thank you for using"));
        close(fd[1]);
        exit(0);
    }
    else{
        wait(NULL);
        close(fd[1]);
        read(fd[0], child_buffer, sizeof(child_buffer));
        printf("%s\n", child_buffer);
        shmdt(parent_shared_memory);
        shmctl(parent_shared_memory_id, IPC_RMID, NULL);
    }

    return 0;
}


