/**********************************************************************
 * Title: Permutation
 *
 * Author: Nic La
 *
 * Purpose: Write a program that will compare two lists, and append any 
 * elements in the second list that doesn't exist in the first.
 * input: ["a","b","c",1,4,], ["a", "x", 34, 4]
 * output: ["a", "b", "c",1,4,"x",34]
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/qr0hg/3102012_challenge_22_easy/
 *
 **********************************************************************/


#include <stdio.h>
#include <string.h>

const int list_length1 = 5;
const int list_length2 = 4;

char list1[list_length1][10] = {"a", "b", "c", "1", "4"};
char list2[list_length2][10] = {"a", "x", "34", "4"};

int main()
{
    int i, j;
    int count = 0;
    
    for(i = 0; i < list_length2; i++){
        for(j = 0; j < list_length1; j++){
            if(i == 0){
                printf("[%s]", list1[j]);
            }
            
            if(strcmp(list2[i], list1[j]) == 0){
                count++;
            }
        }
        if(count == 0){
            printf("[%s]", list2[i]);
        }
        count = 0;
    }
    
    
    
}

















