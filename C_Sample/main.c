/**********************************************************************
 * Title: Checkerboard
 *
 * Author: Nic La
 *
 * Purpose: Your challenge today is to write a program that can draw a 
 * checkered grid (like a chessboard) to any dimension. For instance, 
 * a 3 by 8 board might look like this:
 *
 * Prompt: https://www.reddit.com/r/dailyprogrammer/comments/sv6lw/4272012_challenge_45_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>

// Function to print empty block
void empty_block(int index)
{
    switch(index)
    {
        case 0:
            printf("****");
            break;
        case 1:
            printf("   *");
            break;
        case 2:
            printf("   *");
            break;
        case 3:
            printf("   *");
            break;
        case 4:
            printf("****");
            break;
    }

}

// Function to print filled block
void filled_block(int index)
{
    switch(index)
    {
        case 0:
            printf("****");
            break;
        case 1:
            printf("###*");
            break;
        case 2:
            printf("###*");
            break;
        case 3:
            printf("###*");
            break;
        case 4:
            printf("****");
            break;
    }
}

int main(void)
{
    char line[100];
    int length = 0, height = 0;
    int i, j;
    int index = 0;
    bool block = 0;

    printf("Enter length: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &length);
    
    printf("Enter height: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &height);
    
    // Row
    // 4 * height number or rows + 1
    for(j = 0; j < ((height*4)+1); j++)
    {
        // At the start of each new row
        printf("*");
        if(length%2 != 0)
        {
            block = !block;
        }
        
        // Block
        for(i = 0; i < length; i++)
        {
            if(block == 0)
            {
                // Empty block
                empty_block(index);
            } else if(block == 1)
            {
                // Filled block
                filled_block(index);
            }
            block = !block;
        }
        
        // Increment to next row
        printf("\n");
        if(index != 4)
        {
            index++;
        } else
        {
            index = 1;
            block = !block;
        }

    }
    
    return(0);
}

















