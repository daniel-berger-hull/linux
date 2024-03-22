#include <iostream>

#include <stdio.h> 

//#include <stdlib.h>
//#include <unistd.h>


#define SUCCESS                0
#define ERROR_CREATING_FILE   -1


using namespace std;

int testCharTmpFile()
{
   char str[] = "Hello GeeksforGeeks"; 
   int i = 0;

   cout<<"Will create a tmp file on Linux and write characters into..."<<endl;


    FILE* tmp = tmpfile(); 
    if (tmp == NULL) 
    { 
        cout<<"Unable to create temp file\n"; 
        return ERROR_CREATING_FILE; 
    } 

    cout<<"Temporary file is created (FD is "<<tmp<<" )\n";
    cout<<"Writing chars into...\n";	
    while (str[i] != '\0') 
    { 
        fputc(str[i], tmp); 
        i++; 
    } 
    
    rewind(tmp); 
 
    cout<<"Read and display content of the tmp file...\n"; 
    while (!feof(tmp)) 
        putchar(fgetc(tmp)); 

    cout<<endl;

    return SUCCESS;
}	

int testBinaryTmpFile()
{
   char str[] = "Hello GeeksforGeeks"; 
   int i = 0;
   unsigned int data = 0x1234;
   unsigned int read = 0;
 

   cout<<"Will create a tmp file on Linux and write binary data into..."<<endl;


    FILE* tmp = tmpfile(); 
    if (tmp == NULL) 
    { 
        cout<<"Unable to create temp file\n"; 
        return ERROR_CREATING_FILE; 
    } 

    cout<<"Temporary file is created (FD is "<<tmp<<" )\n";
    cout<<"Writing binary data into...\n";	
    for  (i=0;i<10;i++)
    {
       fwrite(&data,sizeof(unsigned int), 1, tmp );
    }

    
    rewind(tmp); 
 
    cout<<"Read and display content of the tmp file...\n"; 
    for  (i=0;i<10;i++)
    {
       fread(&read,sizeof(unsigned int), 1, tmp );
       cout<<i<<" : " << read << endl;
    }


    cout<<endl;

    return SUCCESS;
}	

   


int main()
{
  //testCharTmpFile();
  testBinaryTmpFile();

  return 0;
}
