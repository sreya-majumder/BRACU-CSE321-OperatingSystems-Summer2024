#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    //Checking whether the numbers are given or not
    if (argc < 2) {
        printf("You have not given any number");
        return -1;
    }

    pid_t processId = fork();

    if (processId == 0) {

        // Child process (Sorting the array in descending order)
        printf("Child process running (Sorting array in descending order)\n");
        execv("./sort",argv);

    } else {

        // Waiting for child process to complete
        wait(NULL);

        // Parent process (Checking whether the array elements are odd or even)
        printf("Parent process running (Checking whether the array elements are odd or even)\n");
        execv("./oddeven",argv);
    }

    return 0;
}

