#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 10 //producers and consumers can produce and consume upto MAX
#define BUFLEN 6
#define NUMTHREAD 2 /* number of threads */

void * consumer(int *id);
void * producer(int *id);

char buffer[BUFLEN];
char source[BUFLEN]; //from this array producer will store it's production into buffer
int pCount = 0;
int cCount = 0;
int buflen;

//initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0,1};
int i = 0;
int j = 0;

int main()
{
    int i;
    /* define the type to be pthread */
    pthread_t thread[NUMTHREAD];
    char source_char[6] = {'a','b','c','d','e','f'};
    strcpy(source, source_char);
    //strcpy(source,"abcdef");
    buflen = strlen(source);
    /* create 2 threads*/
    /* create one consumer and one producer */
    /* define the properties of multi threads for both threads */
    //Write Code Here
    pthread_create(&thread[0], NULL, (void *)producer, &thread_id[0]);
    pthread_create(&thread[1], NULL, (void *)consumer, &thread_id[1]);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    return 0;
}



void * producer(int *id)
{
    /*
    1. Producer stores the values in the buffer (Here copies values from source[] to buffer[]).
    2. Use mutex and thread communication (wait(), sleep() etc.) for the critical section.
    3. Print which produ4. Producer can produce up cer is storing which values using which thread inside the critical section to MAX 
    */
    //Write code here
    int thread_id = *(int *)id;
    while (pCount < MAX) {
        pthread_mutex_lock(&count_mutex);
        while ((i-j) >= BUFLEN) {
            pthread_cond_wait(&full, &count_mutex);
        }

        buffer[i % BUFLEN] = source[pCount % buflen];
        printf("%d produced %c by Thread %d\n", pCount, buffer[i % BUFLEN], thread_id);
        
        i++;
        pCount++;

        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);
        
        sleep(1);

    }
    pthread_exit(NULL);

}

void * consumer(int *id)
{
    /*
    1. Consumer takes out the value from the buffer and makes it empty.

    2. Use mutex and thread communication (wait(), sleep() etc.) for critical section
    3. Print which consumer is taking which values using which thread inside the critical section.
    4. Consumer can consume up to MAX
    */
    //Write code here
    int thread_id = *(int *)id;
    while (cCount < MAX) {
        pthread_mutex_lock(&count_mutex);
        while (i-j<=0) {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }

        printf("%d consumed %c by Thread %d\n", cCount, buffer[j % BUFLEN], thread_id);
        j++;
        cCount++;

        pthread_cond_signal(&full);
        pthread_mutex_unlock(&count_mutex);
        
        sleep(1);

    }
    pthread_exit(NULL);
    
}
