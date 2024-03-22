#include <stdio.h>



void displayClient()
{

   #ifdef USE_WIN32
      printf("This is the WIN32 client function!\n")  ;
   #else
      printf("Using default Linux method\n")  ;
   #endif
}
