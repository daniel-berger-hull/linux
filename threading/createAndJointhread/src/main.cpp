#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


/*
   This example is almost the same as createthread, as instead of having an explicit sleep in the main thread, it uses the join function
   The result is that the main thread will block till Thread #1 (no param) is completed (because it is the shortest),
   then the  main thread blocks again, waiting for Thread #2, and only when #2 is completed, that it exist the program
*/


//We must pass a structure if we want to pass arguments to a thread function
//All the values we want to pass need to be defined in this struct..
struct myThreadParams
{
   int count;
   bool flag;
};


// Function Thread with No Parameters...
void* thread_noParam (void* unused)
{

    printf("No Value passed to this thread...\n");
    usleep(100000);         // Wait a bit, as the other thread will also print something, and it will not look pretty on the screen...

     for (int i=0;i<5;i++)
     {
            fputc ('x', stderr);
            usleep(200000);
     }

     printf("\nthread_noParam completed!\n");
     return NULL;
}


// Function Thread with with Parameters  (Must pass a struct object)...
void* thread_withParam (void* allParams)
{

    myThreadParams *params = (myThreadParams *)allParams;
    printf("Value passed to the thread:  count = %d, flag = %d\n", params->count, params-> flag);
    usleep(100000);
    int numIterations = (params->count > 0) ? params->count : 0;

    //printf("Value passed to the thread:  count = %d\n", params->count);

     for (int i=0;i<numIterations;i++)
     {
            fputc ('y', stderr);
            usleep(200000);
     }

    printf("\nthread_withParam completed!\n");

     return NULL;
}

int main()
{
    pthread_t thread_id, thread_id2;
    myThreadParams params;

    params.count = 15;
    params.flag = true;

    /* Create a new thread. The new thread will run the print_xs function. */
    pthread_create (&thread_id , NULL, &thread_noParam, NULL);
    pthread_create (&thread_id2, NULL, &thread_withParam, &params);

    printf("[Main Thread] Threads are created.. While block this child threads are done...\n");

   pthread_join (thread_id, NULL);          /* Make sure the first thread has finished. */
   printf("\n[Main Thread] Threads 1 (no params) is done...\n");

   pthread_join (thread_id2, NULL);  /* Make sure the second thread has finished. */
   printf("\n[Main Thread] Threads 2 (with myThreadParams params) is done...\n");



    return 0;
}
