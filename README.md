Collection of simple C projects to run on Linux, based on the study of the book 'Advanced Linux Programming'  from New Riders edition (2001).


General Notes:
* fork:   Duplicate the callers process,  so that 2 process exists with the same code.
        The execution of code continues EXACTLY the next line where the fork method been called.

* exec:   Replace the callers process with another one, and continues the execution with the code provided as param

*fork & exec: Use both method, if you want to spawn a new process, but that is will run a different program
              (Which is most case, that is what you want. You don't want to just duplicate same code for a process')
               Steps:  1 - Call fork (so 2 process will exist)
                       2 - on the duplicate process, call exec, with the code you want to run
                          (So that the inial code is not just duplicated. The new process will exectute something else).
