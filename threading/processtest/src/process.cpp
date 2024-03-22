#include <stdio.h>
#include <stdlib.h>


#include <unistd.h>


void displayProcess()
{
  printf ("The process ID is %d\n", (int) getpid ());
  printf ("The parent process ID is %d\n", (int) getppid ());
}


int testLsCommand()
{
  int return_value = system ("ls -l /");
  printf("Value returned is %d\n", return_value);

  return return_value;
}

int testHelloCommand()
{
  int return_value = system ("./hello /");
  printf("Value returned is %d\n", return_value);

  return return_value;
}
	

int main ()
{
  displayProcess();
  // testLsCommand();
  testHelloCommand();

 
  return 0;
}
