/**********************************************************************
 * Title: Store Credit
 *
 * Author: Nic La
 *
 * Prompt source: https://www.reddit.com/r/dailyprogrammer/comments/teua8/592012_challenge_50_easy/
 *
 * Function requirements: INPUT: credit, list array
 *                        OUTPUT: two item positions
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void position(int credit, int list[SIZE])
{
    int i, j;
    
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if((i != j) && (credit == list[i] + list[j]))
            {
                printf("%d, %d\n", i + 1, j + 1);
                exit(8);
            }
        }
    }
    
}

int main()
{
    int credit = 8;
    int list[SIZE] = {2,1,9,4,4,56,90,3};
    
    position(credit, list);
    
    return 0;
}




