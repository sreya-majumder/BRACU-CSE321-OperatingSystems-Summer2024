#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

    //Checking whether the file name is given in command line argument or not 
    if (argc < 2) {
        printf("You have not provided the file name\n");
        return -1;
    }

    //Declaring the variables
    int fileDescriptor;
    char inputBuffer[100];

    //If file exists, opening file / creating file
    fileDescriptor = open(argv[1], O_WRONLY | O_CREAT | O_APPEND , 0600);

    //Taking input until -1 is given and writing in the file
    while(1) {
        printf("Please enter a string: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        //Checking if the input is -1 or not
        if (strcmp(inputBuffer, "-1\n") == 0) {
            break;
        }
        write(fileDescriptor, inputBuffer, strlen(inputBuffer));
    }

    //Closing the file
    close(fileDescriptor);
    return 0;
}
