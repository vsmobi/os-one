#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> 
#include <signal.h>
#include <semaphore.h>
#include <assert.h>
#include <math.h>
#include "queue.h"

sem_t sem;
sem_t endsem;
int MAX;
int n;
int value = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t waitl = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t endm = PTHREAD_MUTEX_INITIALIZER;
struct Queue *q;

void swap(int * a, int * b) {
    int tempt;
    tempt = *a;
    *a = *b;
    *b = tempt;
}

void msort(int * arr, int first, int last) {
    int f = first, l = last, m = arr[(l + f) / 2];

    do {
        while (arr[f] < m)
            f++;
        while (arr[l] > m)
            l--;
        if (f <= l) {
            if (l > f)
                swap(&arr[f], &arr[l]);
            f++;
            l--;

        }
    } while (f <= l);

    if (f < last)
        msort(arr, f, last);

    if (first < l)
        msort(arr, first, l);

}

void printerr() {

    struct Node *param;
    sem_wait(&sem);
    // pthread_mutex_lock(&waitl);
    pthread_mutex_lock(&lock);
    param = pop(q);
    pthread_mutex_unlock(&lock);
    int b;
    int *a = param->arr;
    int firs = param->frs;
    int las = param->ls;
    msort(a, firs, las);
    printf("\n");
    for (b = firs; b <= las; b++) {
        printf("%d  ", a[b], fflush);
    }
    // pthread_mutex_unlock(&endm);
    sem_post(&endsem);
}

int main(int argc, char **argv) {

    if (argc == 3) {
        MAX = atoi(argv[1]);
        n = atoi(argv[2]);
    } else {
        printf("use args Tdefault n=11 max=3 \n");
    }
    srand(2);
    int hsize, b = 0, a[n], i;

    hsize = (n / MAX);

    for (b = 0; b < n; b++) {
        a[b] = rand() % 100;
        printf("%d ", a[b]);
    }

    for (i = 0; i < MAX; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, printerr, NULL);
    }


    q = new_queue();

    for (i = 0; i < MAX; i++) {
        if (i != (MAX - 1)) {
            push(q, a, hsize*i, hsize * i + (hsize - 1));
            // pthread_mutex_unlock(&waitl);
            sem_post(&sem);
        } else {
            push(q, a, hsize*i, n - 1);
            //  pthread_mutex_unlock(&waitl);
            sem_post(&sem);
        }
    }

    for (i = 0; i < MAX; i++) {
        // pthread_mutex_lock(&endm);
        sem_wait(&endsem);
    }


    msort(a, 0, n - 1);
    printf("\n");
    for (b = 0; b < n; b++) {
        printf("%d ", a[b]);
    }
   printf("\n");
    return 0;
}
