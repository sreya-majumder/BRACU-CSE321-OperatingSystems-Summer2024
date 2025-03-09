#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunction(void *threadArg) {
    int threadNum = *((int *)threadArg);

    for (int i = 1; i <= 5; i++) {
        printf("Thread %d prints %d\n", threadNum, (threadNum * 5) + i);
    }

    return 0;
}

int main() {
    pthread_t totalThreads[5];
    int threadArgs[5];

    for (int i = 0; i < 5; i++) {
        threadArgs[i] = i;
        pthread_create(&totalThreads[i], NULL, threadFunction, (void *)&threadArgs[i]);
        pthread_join(totalThreads[i], NULL);
    }

    return 0;
}


