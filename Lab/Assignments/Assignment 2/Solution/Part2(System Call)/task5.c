#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t processId1, processId2, processId3, processId4;

    //Printing Statement of Parent Process
    printf("1. Parent process ID : %d\n", getpid());

    //Creating the child process
    processId1 = fork();

    if (processId1 == 0) {
        //Printing Statement of Child Process
        printf("2. Child process ID: %d\n", getpid());

        //Creating grandchild process 1
        processId2 = fork(); 

        if (processId2 == 0) {
            //Printing Statement of Grand Child Process 1
            printf("3. Grand Child process ID: %d\n", getpid());
        } else {
            //Waiting for grandchild 1 process to finish
            wait(NULL);

            //Creating grandchild process 2
            processId3 = fork(); 

            if (processId3 == 0) {
                //Printing Statement of Grand Child Process 2
                printf("4. Grand Child process ID: %d\n", getpid());
            } else {
                // Waiting for grandchild 2 process to finish
                wait(NULL); 

                //Creating grandchild process 3
                processId4 = fork();

                if (processId4 == 0) {
                    //Printing Statement of Grand Child Process 3
                    printf("5. Grand Child process ID: %d\n", getpid());
                } else {
                    // Waiting for grandchild 3  process to finish
                    wait(NULL);
                }
            }
        }

    } else {
        // Waiting for the child to finish process
        wait(NULL);
    }

    return 0;
}

