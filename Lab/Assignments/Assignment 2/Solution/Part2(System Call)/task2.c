#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t processId1, processId2;
    
    // Creating the child process
    processId1 = fork();

    // Child process
    if (processId1 == 0) { 

        // Creating the grandchild process
        pid_t processId2 = fork();

        // Grandchild process
        if (processId2 == 0) {
            printf("I am grandchild\n");
        } 
        // Child process
        else if (processId2 > 0) { 
            // Waiting for the grandchild process to finish
            wait(NULL);

            //Printing statement of child process
            printf("I am child\n");
        }
        return 0;
    } 
    // Parent process
    else if (processId1 > 0) { 
        // Waiting for the child process to finish
        wait(NULL); 

        // Printing statement of parent process
        printf("I am parent\n");
    }
    return 0;
}
