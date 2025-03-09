#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

//Declaring thread number and user name as global variable
int threadNum;
char *userName;

void *userNameAsciiSum(void *userNameArg) {
    int asciiSum = 0;
    char *userName = (char *)userNameArg;
    while (*userName) {
        asciiSum += *userName++;
    }
    printf("This is Thread %d and the summation is  %d\n", threadNum, asciiSum);
    pthread_exit((int *)asciiSum);
}

int main() {
    pthread_t totalThread[3];
    char userNames[3][100];
    int asciiSums[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter the name of user %d: ", i + 1);
        scanf("%s", userNames[i]);

        threadNum = i + 1;
        userName = userNames[i];

        pthread_create(&totalThread[i], NULL, userNameAsciiSum,  (void *)userNames[i]);
        pthread_join(totalThread[i], (void **)&asciiSums[i]);
    }

    if (asciiSums[0] == asciiSums[1] && asciiSums[1] == asciiSums[2] && asciiSums[0] == asciiSums[2]) {
        printf("Youreka\n");
    } else if (asciiSums[0] == asciiSums[1] || asciiSums[1] == asciiSums[2] || asciiSums[0] == asciiSums[2]) {
        printf("Miracle\n");
    } else {
        printf("Hasta la vista\n");
    }

    return 0;
}

