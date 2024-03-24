#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


using namespace std;

int spawn (char* program, char** arg_list)
{
    pid_t child_pid;

    child_pid = fork (); /* Duplicate this process. */
    if (child_pid != 0)
    {
        sleep(15);
        return child_pid; /* This is the parent process. */
    }
    else {

        execvp (program, arg_list); /* Now execute PROGRAM, searching for it in the path. */
        fprintf (stderr, "an error occurred in execvp\n"); /* The execvp function returns only if an error occurs. */
        abort ();
    }
}


int main ()
{
    int child_status;
    printf ("*** Make sure to have the exectable 'childprocess' in the same folder... ***\n", (int) getpid ());
    printf ("Main process ID %d started...\n", (int) getpid ());

    char* arg_list[] = {
    "./childprocess", /* argv[0], the name of the program. */
    "1",
    "2",

    NULL /* The argument list must end with a NULL. */
    };

    child_status = spawn ("./childprocess", arg_list);
    printf ("Received id for the child  process %d\n", child_status );


    wait (&child_status);

    if (WIFEXITED (child_status))
        printf ("the child process exited normally, with exit code %d\n", WEXITSTATUS (child_status));
    else
        printf ("the child process exited abnormally\n");



    printf ("done with main program\n");
    return 0;
}
