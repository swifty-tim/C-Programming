//
//
//  assignment2.c
//  Assign_2
//
//  Created by Timothy Barnard on 12/03/2014.
//  Copyright (c) 2014 Timothy Barnard. All rights reserved.
//
//
//this program is a simple lotto game with 6 menu options
//its hold the winning numbers in the code

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

//numbers of inputs for user
#define size 6

//declaring prototypes
void lottoMenu(int*, int*);
void playGame(int[],int[]);
void displayNumbers(int[]);
void sortedNumbers(int[]);
void compareNumbers(int[]);
void frequency(int[]);
void exitGame();


int main()
{
    // two varibles to control program
    int control = 0;
    int counter_1 = 0;
    
    while(counter_1 == 0)
    {
        lottoMenu(&counter_1, &control);
    }
    
    return 0;
    
}
/********************************************************/
//function to start game, parameters for two integer variables
// counter_1 to end the game if user inputs no 6 to exit
//control to make sure user inputs 1 first before 2 -6
void lottoMenu(int *counter_1, int *control)
{
    int int_opt = 0;
    
    char opt1;
    int numbers[size]; //array to hold numbers
    static int freqArray[42] = {0}; //stores numbers entered by user
    
    printf("\t\t\tLOTTO\n\n");
    printf("\t\t\tMenu\n");
    printf("\t1: Start\n");
    printf("\t2:Display Numbers\n");
    printf("\t3:Sorted Numbers\n");
    printf("\t4:Compare Numbers\n");
    printf("\t5:Frequency Entered\n");
    printf("\t6:Exit\n");
    
    scanf("%10s", & opt1);
    
    //changing from char to integer
    int_opt = atoi(&opt1);
	
	//error check the user input
	if((int_opt < 0) || (int_opt > 6))
	{
		printf("\nError, Wrong Input\n");
	}
    
    //switch case for menus
    switch(int_opt)
    {
        case 1:
        {
            //call function to start game
            *control = 1;
            printf("\nWelcome to Lotto, Good Luck\n\n");
            playGame( numbers,freqArray);
            break;
        }
            
        case 2:
        {
            //call function to display numbers user entered
            if(*control == 1)
            {
                displayNumbers(numbers);
            }
            else
            {	//error message if 1 is not clicked first
                printf("Play Game First\n\n");
            }
            break;
        }
            
        case 3:
        {
            //call function to display sorted numbers
            if(*control == 1)
            {
                sortedNumbers(numbers);
            }
            else
            {
                printf("Play Game First\n\n");
            }
            break;
        }
            
        case 4:
        {
            //call function to see if user won
            if(*control == 1)
            {
                compareNumbers(numbers);
            }
            else
            {
                printf("Play Game First\n\n");
            }
            break;
        }
            
        case 5:
        {
            //call function to see frequency user enter the numbers
            if(*control == 1)
            {
                frequency(freqArray);
            }
            else
            {
                printf("Play Game First\n\n");
            }
            break;
        }
        case 6:
        {
            //end of game message
            printf("\n\tThank you for playing Lotto\n");
            printf("\n\tCreated by Timothy Barnard\n");
            sleep(3);
            *counter_1 = 1;
            break;
        }
    }//end case
    
}//end lottoMenu function

/********************************************************/
//function for user to play game
//two integer arrays to hold numbers and frequency array
void playGame(int numbers[], int freqArray[])
{
    int counter = 0;
    char numbers_1; //char array to hold numbers entered by user
    int value = 0;
    int j = 0;
    
    printf("\nEnter your 6 Numbers:\n");
    
    for(int i = 0; i < size; i++)
    {
        scanf("%s", &(numbers_1));
        
        //converts char array to integer array
        value = atoi(&(numbers_1));
        
        //stores each number in the integer array
        (*(numbers + i)) = value;
    }
    
	
    
    //loop to error check and if all clear, then input into frequency array
    for(int i = 0; i < size; i++)
    {
        
        if((*(numbers + i)) == (*(numbers + (i + 1))))
        {
            //adds to counter to display error message
            counter = 1;
        }
        else if (*(numbers + i) < 0 || (*(numbers + i)) > 42)
        {
            counter = 1;
        }
        else
        {
            //stores numbers in freqArray
            j = (*(numbers + i));
            
            (*(freqArray + j))++;
        }
    }//end for
    //error message check
    if(counter > 0)
    {
        printf("\nInvalid Input, Try agin\n");
        printf("Wait....\n");
        sleep(3);
		//goes back to start of function
        playGame(numbers, freqArray);
    }//end if
    
}//end playGame function

/********************************************************/
//function to display numbers entered by user
//integer array to hold numbers entered by user
void displayNumbers(int numbers[])
{
    printf("The Numbers you Entered are as follows: \n");
    
    //loop to display numbers with | break between
    for(int i = 0; i < size; i++)
    {
        printf("%d", *(numbers+ i));
        printf(" | ");
    }
}//end displayNumbers function

/********************************************************/
//function to sorted the numbers
//integer array passed in to sort the numbers entered by user
void sortedNumbers(int numbers[])
{
    //bubble sort algorithm to sort numbers from small to biggest
    int a,b,n, swap = 0;
    n = size;
    
    for (a = 0 ; a < ( n - 1 ); a++)
    {
        for (b = 0 ; b < n - a - 1; b++)
        {	// > used to increasing order
            if (*(numbers + b) > (*(numbers +( b+1))))
            {
                swap = (*(numbers + b));
                (*(numbers + b)) = (*(numbers + (b+1)));
                (*(numbers + (b+1))) = swap;
            }
        }
    }
	//loop to print out the order numbers
    for(int i = 0; i < size; i++)
    {
        printf("%d", *(numbers+i));
        printf(" | ");
        
    }
}//end sortedNumbers function

/********************************************************/
//function to check winning numbers
//integer array to check numbers to winning numbers
void compareNumbers(int numbers[])
{
    int win = 0;
    int winBonus = 42;
    
    //winning numbers
    int lottoNumbers[size] = {1,3,5,7,9,11};
    
    //loop to check each number with winning numbers and bonus number
    for(int i = 0; i < size;i++)
    {
        for(int j =0; j < size; j++)
        {
            if(*(lottoNumbers + i) == *(numbers + j))
            {
                win++;
            }
            else if(*(lottoNumbers + i) == winBonus)
            {
                win = + 100;
            }
        }
        
    }//end for
    
    //switch case to show results
    switch(win)
    {
        case 6: //6 correct numbers
        {
            printf("\t\nJack Pot\n");
            break;
        }
        case 105: //5 correct numbers + jackpot
        {
            printf("\t\nNew Car\n");
            break;
        }
        case 5: //5 correct numbers
        {
            printf("\t\nHoliday\n");
            break;
        }
        case 104: //4 correct numbers + jackpot
        {
            printf("\t\nWeekend Away\n");
            break;
        }
        case 4: //4 correct numbers
        {
            printf("\t\nNight Out\n");
            break;
        }
        case 103: //3 correct numbers + jackpot
        {
            printf("\t\nCinema Ticket\n");
        }
        default: //default message
        {
            printf("\t\nYou Loose");
        }
    }
    
    
} //end compareNumbers function

/********************************************************************/
//function to show frequency of numbers entered by user
void frequency(int freqArray[])
{
    
    for(int i = 0; i < 42; i++)
    {
		//checks if each element hold a number greater than 0
        if(*(freqArray + i) > 0)
        {
            printf("\tNumber %d has been selected %d times\n", i, *(freqArray + i));
        }
    }
}//end function






