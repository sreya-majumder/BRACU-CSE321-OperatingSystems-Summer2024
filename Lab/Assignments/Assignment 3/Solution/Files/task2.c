#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>

struct msg{
    long int type;
    char txt[6];  
};

int main() {
    int message_id;
    struct msg message;
    
    message_id = msgget((key_t)25, 0666 | IPC_CREAT);
    if (message_id == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Please enter the workspace name:\n");
    char workspace_name[6];
    scanf("%s", workspace_name); 

    if (strcmp(workspace_name, "cse321") != 0) {
        printf("Invalid workspace name\n");
        msgctl(message_id, IPC_RMID, NULL); 
        exit(0);
    }

    strncpy(message.txt, workspace_name, 6); 
    message.type = 1;  
    msgsnd(message_id, &message, sizeof(message), IPC_NOWAIT);
    
    printf("Workspace name sent to otp generator from log in: %s\n\n", message.txt);

    pid_t otp_pid = fork();

    if (otp_pid < 0) {
        perror("fork");
        exit(1);
    }

    if (otp_pid == 0) {
        struct msg otp_message;
        msgrcv(message_id, &otp_message, sizeof(otp_message), 1, IPC_NOWAIT);
        printf("OTP generator received workspace name from log in: %s\n\n", otp_message.txt);

        int otp = rand()%10000;
        snprintf(otp_message.txt, sizeof(otp_message.txt), "%04d", otp); 
        otp_message.type = 2;

        msgsnd(message_id, &otp_message, sizeof(otp_message), IPC_NOWAIT);
        printf("OTP sent to login from OTP generator: %s\n", otp_message.txt);
        
        otp_message.type = 3;
        msgsnd(message_id, &otp_message, sizeof(otp_message), IPC_NOWAIT);
        printf("OTP sent to mail from OTP generator: %s\n", otp_message.txt);

        
        pid_t mail_pid = fork();

        if (mail_pid == 0) {
            struct msg mail_message;

            msgrcv(message_id, &mail_message, sizeof(mail_message), 3, 0);
            printf("Mail received OTP from OTP generator: %s\n", mail_message.txt);

            mail_message.type = 4;
            msgsnd(message_id, &mail_message, sizeof(mail_message), IPC_NOWAIT);
            printf("OTP sent to log in from mail: %s\n", mail_message.txt);

            exit(0);

        } else if(mail_pid>0) {
            wait(NULL);
            exit(0);
        }
    } else if(otp_pid>0){
        wait(NULL);

        struct msg login_msg_otp;
        msgrcv(message_id, &login_msg_otp, sizeof(login_msg_otp), 2, 0);
        printf("Log in received OTP from OTP generator: %s\n", login_msg_otp.txt);

        struct msg login_msg_mail;
        msgrcv(message_id, &login_msg_mail, sizeof(login_msg_mail), 4, 0);
        printf("Log in received OTP from mail: %s\n", login_msg_mail.txt);

        if (strcmp(login_msg_otp.txt, login_msg_mail.txt) == 0) {
            printf("OTP Verified\n");
        } else {
            printf("OTP Incorrect\n");
        }
        msgctl(message_id, IPC_RMID, NULL);
    }

    return 0;
}

