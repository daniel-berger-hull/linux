#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include<unistd.h>


extern char** environ;


int main()
{
   char message[30];

   printf("Display all environment variables set on the OS...\n");
   printf("=================================================\n");

   // This section diplays all the  environment variables set ...
   // Equivalent to enter the command 'env' from a Terminal window
   char** var;
   for (var = environ; *var != NULL; ++var)
     printf ("%s\n", *var);
  


   printf("\nTest if my custom SERVER_NAME variable is set...\n");
   printf("=================================================\n");


   char* server_name = getenv ("SERVER_NAME");
   if (server_name == NULL)
   {
         printf("SERVER_NAME is not set!!!\n");
         printf("You can set the env variable with command:\n");
         printf("export SERVER_NAME=<YourValue>\n");


         server_name = "server.my-company.com";
   }
     

   printf ("accessing server %s\n", server_name);







   return 0;
}
