#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int testHelloCommand()
{
  int return_value = system ("./hello /");
  printf("Value returned is %d\n", return_value);

  return return_value;
}
	

int main ()
{
 pid_t child_pid;
 printf ("Main program process ID is %d\n", (int) getpid ());

  child_pid = fork ();
  if (child_pid != 0) {
     printf ("this is the parent process, with id %d\n", (int) getpid ());
     printf ("the child’s process ID is %d\n", (int) child_pid);
  }
  else
    printf ("this is the child process, with id %d\n", (int) getpid ());

  printf ("Process ID %d will complete\n", (int) getpid ());
 
  

  return 0;
}
