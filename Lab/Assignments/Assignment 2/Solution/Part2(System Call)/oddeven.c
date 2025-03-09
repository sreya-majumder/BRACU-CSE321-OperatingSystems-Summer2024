#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    //Checking whether the numbers are given or not
    if (argc < 2) {
        printf("You didn't give the numbers\n");
        return -1;
    }

    //Declaring variables
    int arrlength = argc - 1;
    int inputArr[arrlength];

    //Creating array with the given numbers
    for (int i = 1; i < argc; i++) {
        inputArr[i - 1] = atoi(argv[i]);
    }

    //Checking whether the number is odd or even
    for (int j = 0; j < arrlength; j++) {
        if (inputArr[j] % 2 == 0){
            printf("The element %d at index %d is even\n", inputArr[j],j);
        }else{
            printf("The element %d at index %d is odd\n", inputArr[j],j);
        }
    }

    return 0;
}


