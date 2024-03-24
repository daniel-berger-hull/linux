#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DELAY_TIME    180           // Having too much sleep time is not really appropriate for the projects of this repo... 3 minutes is far enough...

/*
   Test program to be used as a child process for the projects in the /linux/threading folder.
   Make sure to copy the executable of this project into the threading project that require child process to use used for test...
*/


bool isDelayAsked(int argc,char *argv[])
{
    if ( argc < 3 )                  return false;          // You must pass -d and a numeric value in the command line, so no delay for sure!

    if ( strcmp(argv[1],"-d") != 0)  return false;          // only '-d' is accepted as param, if a delay is asked by the caller

    int delay = atoi(argv[2]);

    if ( delay <= 0 || delay > MAX_DELAY_TIME )   return false;

    return true;
}

// All params are passed for the sake of simplicity and keep methods with the same signature
// For instance, the argc is not relevent here. Same as the 2 first strings in the argv...
int parseDelayParam(int argc,char *argv[])
{
    return atoi(argv[2]);;
}


int main(int argc, char *argv[])
{
    printf("Child Process PID #%d\n", (int) getppid());

    if ( isDelayAsked(argc,argv) )
    {
        int sleepTime = parseDelayParam(argc,argv);
        printf( "Child process will sleep %d seconds...\n", sleepTime );
        sleep(sleepTime);
    }

    printf( "Child process terminate\n" );

    return 0;
}
