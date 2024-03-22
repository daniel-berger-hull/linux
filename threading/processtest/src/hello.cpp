#include <stdio.h>
#include<unistd.h>


int main()
{

  printf ("Hello process ID is %d\n", (int) getpid ());
  printf ("Hello's parent process ID is %d\n", (int) getppid ());

  printf("The program is started...\n");
  sleep(3);
  printf("exit!\n");
	
 return 0;
}
