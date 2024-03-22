#include <stdio.h>
#include <unistd.h>


//int main()
int main( int argc, char *argv[] )
{
   printf ("Child process ID %d:\n", (int) getpid ());
   printf ("\tNumber of argument passed is %d\n", argc);
   printf ("\tFirst argument passed (argv[0]) is %s\n", argv[0]);

   if (argc >= 2)
   {
      printf ("\tListing extra arguments:\n");
      for (int i=1;i<argc;i++)   printf ("\tArgument[%d] = %s\n", i, argv[i]);
   }

   //sleep(3);
   printf("Child process terminated\n");

  return 0;
}
