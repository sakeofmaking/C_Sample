/**********************************************************************
 * Title: Bitstring Population Count
 *
 * Author: Nic La
 *
 * Prompt: The population count of a bitstring is the number of set bits
 * (1-bits) in the string. For instance, the population count of the number 
 * 23, which is represented in binary as 10111 is 4.
 * Your task is to write a function that determines the population count of 
 * a number representing a bitstring
 *
 * Prompt source: https://www.reddit.com/r/dailyprogrammer/comments/szz5y/4302012_challenge_46_easy/
 *
 * Requirements:
 * Ask for number
 *      Convert number to binary (bitstring)
 * Count number of set bits in bitstring
 **********************************************************************/

#include <stdio.h>

// Convert number to binary string
// Function adapted from https://blog.udemy.com/c-programs-to-convert-decimal-to-binary/
int decimal2binary(int decimal)
{
    int d[20];
    int i = 0;
    int count = 0;
    while(decimal>0)
    {
        d[i]=decimal%2;
        i++;
        decimal=decimal/2;
    }
    for(int j=i-1;j>=0;j--)
    {
        // Count number of set bits
        if(d[j] == 1)
        {
            count++;
        }
    }
    
    return(count);
}

int main(void)
{
    char line[100];
    int num = 0;
    
    // Ask for number
    printf("Enter number: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &num);
    
    printf("Population count of %d is %d.\n", num, decimal2binary(num));
    
    return(0);
}













