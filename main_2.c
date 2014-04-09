//
//  main.c
//  prog_struct
//
//  Created by Timothy Barnard on 08/03/2014.
//  Copyright (c) 2014 Timothy Barnard. All rights reserved.
//

#include <stdio.h>

void database(int, char[], float);

struct store {
    int age;
    char * name;
    float salary;
}sstore;

int main()
{
    sstore.age = 16;
    sstore.name = "Timothy";
    sstore.salary = 67000.02;
   
	database(sstore.age,sstore.name,sstore.salary);
    
    return 0;
    
}

void database(int age, char name[], float salary)
{
    printf("%s is %d years old and annual salary is %.2f\n",name,age, salary);
}
