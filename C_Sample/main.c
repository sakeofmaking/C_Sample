/**********************************************************************
 * Title: Target Number
 *
 * Author: Nic La
 *
 * Purpose: Write a program that takes a list of integers and a target number 
 * and determines if any two integers in the list sum to the target number. 
 * If so, return the two numbers. If not, return an indication that no such 
 * integers exist.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/reago/3262012_challenge_30_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 12

int main()
{
    int num_list[SIZE] = { 1, 2, 3, 4, 5, 6, 34, 24, 15, 8, 13, 7 };
    int target_num = 42;
    int i, j;
    bool exist = 0;
    
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(((num_list[i] + num_list[j]) == target_num) && (i != j)){
                printf("%d, %d\n", num_list[i], num_list[j]);
                exist = 1;
            }
        }
    }
    
    if(exist == 0){
        printf("No such integers exist\n");
    }

}





















