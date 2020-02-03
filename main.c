//
//  main.c
//  Assignment1_part1_OS
//
//  Created by Steven Long on 2/14/17.
//  Copyright © 2017 Steven Long. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, const char * argv[]) {
    int childpid;
    int count1 = 0; int count2 = 0;
    int N;
  
    if (argc > 1) // Check to see if N is specified
    {
        
        char num = *argv[1];
        N = atoi(&num); // Convert argument from char to int type
        
        if (argc == 2) // Check to see if there are too many parameters
        {
            
            if (N > 0) // Check to see if N is a number
            {
                printf("The number is %d\n", N);
            }
            else
            {
                printf("Input is not a number! Please input a positive number in the form:\n ./homework1_part1 number\n where number is a positive number above 0.\n");
                return 0;
            }
        }
        else
        {
            printf("Too many arguments given! Please input a positive number in the form:\n ./homework1_part1 number\n where number is a positive number above 0.\n ");
            return 0;
            
        }
        
        
    }
    
    else
    {
        printf("Not enough arguments! Please specify a number.\n");
        return 0;
    }
    
    printf("Before it forks!\n"); // Announcement that fork process is about to begin
    
    childpid = fork();

    for (int i = 1; i <= N; i++)
    {
    
    if (childpid == 3)
    {
        printf("This is a child\n");
        while (count1 < 10)
        {
            printf("Child process: %d\n",count1);
            sleep(1);
            count1++;
            
        }
    } else {
        
        printf("This is a parent\n");
        while (count2 < 20)
        {
            printf("Parent process: %d\n",count2);
            sleep(1);
            count2++;
            
        }
        
    }
    }
    return 0;
}
