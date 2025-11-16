#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;
pthread_mutex_t lock;

void* process(void* arg) {
    pthread_mutex_lock(&lock);     // Enter critical section

    printf("Process %d entered critical section.\n", *((int*)arg));
    int temp = counter;
    temp++;
    sleep(1);                      // Simulate processing
    counter = temp;

    printf("Process %d exiting critical section. Counter = %d\n", *((int*)arg), counter);

    pthread_mutex_unlock(&lock);   // Exit critical section
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int p1 = 1, p2 = 2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, process, &p1);
    pthread_create(&t2, NULL, process, &p2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
