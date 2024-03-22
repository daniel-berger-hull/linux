This code is testing the Linux fork and exec method. As red in p49 of the linux_programming_book, the exec method
spawn another program, and the parent program is immediately terminated. So to address this, the fork method is used
 first to create a 'clone' process, and the cloned process is then started with the exec method.
 

 Make sure to compile the child source 'child.cpp', to run the project
    gcc child.cpp -o child.o

