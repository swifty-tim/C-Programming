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
    char name[10];
    float salary;
};

int main()
{
    
    struct store employee;
    
    employee.age = 21;
    employee.name[10] = "Timothy";
    employee.salary = 60,000;
    
    database(employee.age, name, employee.salary);
    
    return 0;
    
}

void database(int age, char name[], float salary)
{
    printf("%s is %d years old and annual salary is %.2f",name,age, salary);
}
