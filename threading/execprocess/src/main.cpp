#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>



using namespace std;

int spawn (char* program, char** arg_list)
{
    pid_t child_pid;

    child_pid = fork (); /* Duplicate this process. */
    if (child_pid != 0)

        return child_pid; /* This is the parent process. */
    else {

        execvp (program, arg_list); /* Now execute PROGRAM, searching for it in the path. */
        fprintf (stderr, "an error occurred in execvp\n"); /* The execvp function returns only if an error occurs. */
        abort ();
    }
}


int main ()
{
    printf ("Main process ID %d started...\n", (int) getpid ());

    char* arg_list[] = {
    "./child.o", /* argv[0], the name of the program. */
    "1",
    "2",

    NULL /* The argument list must end with a NULL. */
    };

    spawn ("./child.o", arg_list);

    printf ("done with main program\n");
    return 0;
}
