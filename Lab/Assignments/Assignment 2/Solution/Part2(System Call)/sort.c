#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    //Checking whether the numbers are given or not
    if (argc < 2) {
        printf("You didn't give the numbers");
        return -1;
    }

    //Declaring variables
    int arrlength = argc - 1;
    int desSorArr[arrlength];

    //Creating array with the given numbers
    for (int i = 1; i < argc; i++) {
        desSorArr[i - 1] = atoi(argv[i]);
    }

    //Sorting using selection sort
    for (int j = 0; j < arrlength; j++) {
        for (int k = j + 1; k < arrlength; k++) {
            if (desSorArr[j] < desSorArr[k]) {
                int tempVar = desSorArr[j];
                desSorArr[j] = desSorArr[k];
                desSorArr[k] = tempVar;
            }
        }
    }

    //Printing the values in descending order
    printf("The descending order sorted array:\n");
    for (int val = 0; val < arrlength; val++) {
        printf("%d ", desSorArr[val]);
    }
    printf("\n");
    return 0;
}


