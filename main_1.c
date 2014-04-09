//Created by: Timothy Barnard
// Date: 11/02/2014
//This program asks the user to input a name and checks if same name in mem

#include <stdio.h>
#include <string.h>


int main()

 {
     char name[8] = "Timothy";
     char *name1;
     
     printf ("Please Enter your name:\n");
     
     scanf("%s",*name1);
     
     if(strcmp(name,name1)==0)
     {
         printf("Name Found!\n");
     }
     else
     {
         printf("Name not Found\n");
     }

	return 0;
}