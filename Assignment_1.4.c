/*
<--------------------------------Problem Statement-------------------------------->
You are required to write a C/C++ program to perform the following tasks:
1. Generate 50 random integers
2. Determine the highest base of each of randomly generated 50 integers using
the formula: Highest base of an integer = max(all the digits in an
integer) + 1. For example, the highest base of 456 = max(4,5,6)
= 6+1 = 7.

3. Count how many Random Integers belong to different highest bases (High-
est base Frequency over different bases).

Your program should adhere to the following requirements:
• The program should generate 50 random integers in any range.
• The program should also print a nice message for each of the 50 Random
Integers, saying that ”The Highest Base of a 5294967296 is 10.”
*/




#include <stdio.h>         // these libraries provide functions for input/output operations, memory allocation, and time-related functions
#include <stdlib.h>
#include <time.h>          // generate different for different times

unsigned long long generateRandomNumber(unsigned long long min, unsigned long long max)       // generating 50 unsigned random integer between min and max (inclusive)
{
    return ((unsigned long long)rand() % (max - min + 1)) + min;                              // no issues we if remove it 
}



int findHighestBase(unsigned long long number)                                           // now here we are creating a function to find the highest digit in a number
{ 
    int maxDigit = 0;                                                                    //  initializing a variable(see for maximum digit)
    while (number > 0)                                                                   // extracting each digit one by one , 
    {
        int digit = number % 10;
        if (digit > maxDigit) 
        {                                                          // current digit ko maxdigit jo aya hai usse compare krega then agr ha ya na toh uske according 10 se phit divide kr dega
            maxDigit = digit;
        }
        number /= 10;
    }
    return maxDigit + 1;
}

int main() 
{
   
    srand(time(0));                                                // now here we are seeding the random number generator with the current time

    int highestBaseFrequency[10] = {0};                            // here we have made an array to store the frequency of each highest base (0 to 9)

    for (int j = 0; j < 50; j++)                                   //generating the first digit (between 6 and 9) as asked in the question
    {                                
        
        int firstDigit =  generateRandomNumber(6, 9);              // generating a random number from 6 to 9

        
        unsigned long long base = 0;                      
        for (int i = 0; i < 9; i++)                                // generating the remaining 9 digits randomly (between 0 and 9)
        {            
            base = base * 10 + generateRandomNumber(0, 9);         // generating a random number from 0 to 9
        }

        unsigned long long randomNumber = (unsigned long long)firstDigit * 1000000000ULL + base;     // here we are combining both to get the 10-digit random integer

        printf("Random 10-digit integer %d: %llu\n", j + 1, randomNumber);
        printf("The Highest Base of a %llu is %d.\n", randomNumber, findHighestBase(randomNumber));

       
        int highestBase = findHighestBase(randomNumber);         // now for here we are updating the frequency of the highest base in the array jo  upr banaya tha findHighestBase
        highestBaseFrequency[highestBase - 1]++;
    }

    printf("\nFrequency of each Highest Base:\n");              // now here we are writing the code to print the frequency of each highest base
    for (int i = 0; i < 10; i++) {
        printf("Highest Base %d: %d\n", i + 1, highestBaseFrequency[i]);
    }

    return 0;
}
