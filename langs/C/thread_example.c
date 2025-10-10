#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void* myThread(void* id)
{
    // Thread-local variable (POSIX supports C11's _Thread_local keyword too)
    int var = 27;
    var += 6;

    // Print ID of current thread and address of var
    printf("Thread ID:[%d], Value of var: %d\n", *(int*)id, var);
    printf("Thread ID:[%d], &var: %p, Value: %d\n", *(int*)id, (void*)&var, var);

    return NULL;
}

void* myStaticThread(void* id)
{
    // Thread-local variable (POSIX supports C11's _Thread_local keyword too)
    static int var = 27;
    var += 6;

    // Print ID of current thread and address of var
    printf("Thread ID:[%d], Value of var: %d\n", *(int*)id, var);
    printf("Thread ID:[%d], &var: %p, Value: %d\n", *(int*)id, (void*)&var, var);

    return NULL;
}

int main()
{
    pthread_t id[NUM_THREADS];
    int arr[NUM_THREADS] = {10, 11, 12, 13, 14};

    // Creating 5 threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&id[i], NULL, myThread, &arr[i]);
    }

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(id[i], NULL);
    }

    printf("\n\nNOW WITH STATIC INT VAR \n\n");
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&id[i], NULL, myStaticThread, &arr[i]);
    }

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(id[i], NULL);
    }
    return 0;
}

