#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include<unistd.h>


extern char** environ;


int main()
{
   char message[30];

   printf("Main program...\n");


   char* server_name = getenv ("SERVER_NAME");
   if (server_name == NULL)
     server_name = "server.my-company.com";

   printf ("accessing server %s\n", server_name);





   // This section diplays all the  environment variables set ...
/*   char** var;
   for (var = environ; *var != NULL; ++var)
     printf ("%s\n", *var);
  */


   //printf("Calling Businnes Function: ");
   //displayClient();

   //strncpy(message, "Daniel Berger", 30);
   //log(message);

   return 1;
}
