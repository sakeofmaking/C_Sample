/**********************************************************************
 * Title: Separate Even From Odd
 *
 * Author: Nic La
 *
 * Prompt: Take an array of integers and partition it so that all the 
 * even integers in the array precede all the odd integers in the array. 
 * Your solution must take linear time in the size of the array and operate 
 * in-place with only a constant amount of extra space.
 * Your task is to write the indicated function.
 *
 * Prompt source: https://www.reddit.com/r/dailyprogrammer/comments/t78m8/542012_challenge_48_easy/
 *
 * Note:
 * Linear time means looping through the array once. In-place means ordering 
 * the one list as you loop through it and then returning it when done.
 *
 * Implementation:
 * Loop through the array once. If even integer, bring to the front of 
 * the array and move on to the next integer.
 **********************************************************************/

#include <stdio.h>
#define SIZE 10

int main(void)
{
    int integer_array[SIZE] = {43, 85, 28, 48, 57, 10, 53, 27, 90, 34};
    int i, j, k, m;
    int temp;
    int index = 0;
    
    // Print original array
    printf("Original array: ");
    for(m = 0; m < SIZE; m++)
    {
        printf("[%d]", integer_array[m]);
    }
    
    // Place even integers in front
    for(i = 0; i < SIZE; i++)
    {
        if(integer_array[i]%2 == 0)
        {
            temp = integer_array[i];
            k = i;
            while(k != index)
            {
                integer_array[k] = integer_array[k - 1];
                k--;
            }
            integer_array[index] = temp;
            index++;
        }
    }
    
    // Print new array
    printf("\nNew array:      ");
    for(j = 0; j < SIZE; j++)
    {
        printf("[%d]", integer_array[j]);
    }
    
    return(0);
}











