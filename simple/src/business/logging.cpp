#include <stdio.h>
#include <unistd.h>


void  log(const char* message)
{
  printf("Logging message: %s\n");  
  printf("sleeping 2 sec...\n");  
  sleep(2);
  printf("awake!\n");  

//  fprintf(stderr, "Logging Error: %s\n");
  

}
