#include <iostream>

#include <stdlib.h>
#include <unistd.h>


typedef int temp_file_handle;

temp_file_handle write_temp_file (char* buffer, size_t length)
{
   char temp_filename[] = "/tmp/temp_file.XXXXXX";  /* Create the filename and file. The XXXXXX will be replaced with characters that make the filename unique. */
   int fd = mkstemp (temp_filename);

   unlink (temp_filename);                          /* Unlink the file immediately, so that it will be removed when the file descriptor is closed. */
   write (fd, &length, sizeof (length));            /* Write the number of bytes to the file first. */

   write (fd, buffer, length);
  
   return fd;
}

char* read_temp_file (temp_file_handle temp_file, size_t* length)
{
   char* buffer;
   int fd = temp_file;                      /* The TEMP_FILE handle is a file descriptor to the temporary file. */
   
   lseek (fd, 0, SEEK_SET);                /* Rewind to the beginning of the file. */
   read (fd, length, sizeof (*length));    /* Read the size of the data in the temporary file. */

   buffer = (char*) malloc (*length);     /* Allocate a buffer and read the data. */
   read (fd, buffer, *length);

   close (fd);                           /* Close the file descriptor, which will cause the temporary file to go away. */

   return buffer;
}







using namespace std;

int main()
{
   cout<<"Will create a test a tmp file on Linux..."<<endl;




   long long int s64          =  -1152921504606846975;
   long long int s642         =  -9000000000000000000;

   unsigned long long int u64 = 0xffffffffffffffff;


   cout<<"Value of s64 is "  <<s64<<endl;
   cout<<"Value of s642 is " <<s642<<endl;
   cout<<"Value of u64 is " <<u64<<endl;


   return 0;
}
