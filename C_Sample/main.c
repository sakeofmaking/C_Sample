/**********************************************************************
 * Title: Array Duplicates
 *
 * Author: Nic La
 *
 * Purpose: The array duplicates problem is when one integer is in an array 
 * for more than once. If you are given an array with integers between 1 and 
 * 1,000,000 or in some other interval and one integer is in the array twice. 
 * How can you determine which one? Your task is to write code to solve the 
 * challenge.
 *
 * Note: try to find the most efficient way to solve this challenge.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/r59kk/3202012_challenge_28_easy/
 *
 **********************************************************************/

#define SIZE 10

#include <stdio.h>


int main()
{
    int original_list[SIZE] = { 8, 9, 7, 5, 7, 4, 3, 2, 1, 6 };
    int new_list[SIZE];
    int i, j, k, m;
    
    // Store list in new array
    for(i = 0; i < SIZE; i++){
        new_list[i] = original_list[i];
    }
    
    // Sort new array in increasing order
    for(j = 0; j < SIZE; j++){
        for(k = 0; k < SIZE; k++){
            if(new_list[j] < new_list[k]){
                new_list[j] += new_list[k];
                new_list[k] = new_list[j] - new_list[k];
                new_list[j] -= new_list[k];
            }
        }
    }
    
    // Compare adjacent elements
    // If equal, print duplicates
    for(m = 0; m < SIZE; m++){
        if(new_list[m] == new_list[m+1]){
            printf("[%d]", new_list[m]);
        }
    }
}





















