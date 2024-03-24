
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_EVENTS_TO_SIMULATE   50


sig_atomic_t sigusr1_count = 0;
void handler (int signal_number)
{
    ++sigusr1_count;
}


void simulateAction(int nbrEvents)
{
    if (nbrEvents <=0 || nbrEvents > MAX_EVENTS_TO_SIMULATE)  return;

    for (int i=0;i<nbrEvents;i++)
    {
       printf(".\n");
       sleep(1);
    }


}

using namespace std;

int main()
{
   struct sigaction sa;
   memset (&sa, 0, sizeof (sa));
   sa.sa_handler = &handler;
   sigaction (SIGUSR1, &sa, NULL);

   printf("Main process running at PID #%d\n", (int) getpid());

   simulateAction(15);


    printf ("SIGUSR1 was raised %d times\n", sigusr1_count);
   printf("Terminate Main process\n");

    return 0;
}
