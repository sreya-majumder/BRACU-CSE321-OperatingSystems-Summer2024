#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* funcThread(void* threadArg) {
    int threadNum = *((int*)threadArg);
    printf("thread-%d running\n", threadNum);
    sleep(1);
    printf("thread-%d closed\n", threadNum);
    sleep(1);
    return 0;
}

int main() {
    pthread_t totalThreads[5];
    int threadArgs[5];

    for (int i = 0; i < 5; i++) {
        threadArgs[i] = i + 1; 
        pthread_create(&totalThreads[i], NULL, funcThread, (void*)&threadArgs[i]);
        pthread_join(totalThreads[i], NULL); 
    }

    return 0;
}

