
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>




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

     for (int i=0;i<25;i++)
     {
            //fputc ('x', stderr);
            usleep(100000);
     }

     return NULL;
}


// Function Thread with with Parameters  (Must pass a struct object)...
void* thread_withParam (void* allParams)
{

    myThreadParams *params = (myThreadParams *)allParams;
    printf("Value passed to the thread:  count = %d, flag = %d\n", params->count, params-> flag);
    int numIterations = (params->count > 0) ? params->count : 0;

    //printf("Value passed to the thread:  count = %d\n", params->count);

     for (int i=0;i<numIterations;i++)
     {
            fputc ('y', stderr);
            usleep(100000);
     }

     return NULL;
}

int main()
{
    pthread_t thread_id, thread_id2;
    myThreadParams params;

    params.count = 5;
    params.flag = true;

    /* Create a new thread. The new thread will run the print_xs function. */
    pthread_create (&thread_id , NULL, &thread_noParam, NULL);
    pthread_create (&thread_id2, NULL, &thread_withParam, &params);

    printf("Thread #1 is %d\n", thread_id );

    sleep(5);

    return 0;
}
