//
//  main_3.c
//
//
//  Created by Timothy Barnard on 11/03/2014.
//
//This Program asks the user for country and then displays the city

#include <stdio.h>
#include <string.h>

#define SIZE 10

//delcare prototypes
void lower_string(char*);
void check_string(char*,char*[]);
void city_print(char*,char*[],char*[]);


int main ()
{
    //two char array to hold countries and cities
    
    char *country[SIZE] = { "austrailia","belgium", "china",
                            "denmark","england",
                            "france", "greece", "ireland",
                            "scotland","russia"
                            };
    
    char *city[SIZE] = { "Canberra","Brussels", "Beijing",
                        "Copenhagen","London",
                        "Paris", "Athens", "Dublin",
                        "Edinburgh","moscow"
                        };
    
	char user[21]; //char array to hold user input
    
    
    
    printf("Please Enter a Country\n");
    
    scanf("%s",user);
    
    //call lower_case function to put all char to lowercase
    lower_string(user);
    
    //call function to check if user inputted a country from list
    check_string(user,country);
    
    //call function to print out city of country
    city_print(user, country, city);
    
    
    return 0;
}

//function to lower case the letters incase of error
void lower_string(char *user)
{
    while(*user)
    {
        if ( *user >= 'A' && *user <= 'Z' )
        {
            *user = *user + 32;
        }
        user++;
    }
}
//function to check if user enter a country from memory
void check_string(char *user, char *country[])
{
    int counter = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        if (strcmp(user, country[i])==0)
        {
            counter++;
        }
    }
    if(counter == 0)
    {
        printf("Wrong country inputted\n");
    }
    
}

//function to display city
void city_print(char *user, char*country[], char*city[])
{
    //loop to check country to city
    for(int i = 0; i < SIZE; i++)
    {
        //compares the user input to country array
        if(strcmp(user, country[i])==0)
        {
            printf("%s\n\n",  city[i]);
        }
    }
    
}

