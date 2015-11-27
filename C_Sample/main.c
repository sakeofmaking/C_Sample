/**********************************************************************
 * Title: Permutation
 *
 * Author: Nic La
 *
 * Purpose: Input: a number
 * Output : the next higher number that uses the same set of digits.
 * 
 * Example: Input: 429
 *          Output: 492
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/qp3ub/392012_challenge_21_easy/
 *
 * permute function adapted from http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
 *
 **********************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num_array[100];
int greater_array[100];
int count = 0;

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
 This function takes three parameters:
 1. String
 2. Starting index of the string
 3. Ending index of the string. */
void permute(char *a, int l, int r)
{
    int i;
    
    if (l == r){
        num_array[count] = atoi(a);
        count++;
    } else{
        for (i = l; i <= r; i++){
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i)); //backtrack
        }
    }
}

int main()
{
    char line[100];
    int j, k;
    int count2 = 0;
    int min = 0;
    
    printf("Enter number: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line)-1] = '\0';
    
    int n = (int)strlen(line);
    permute(line, 0, n-1);
    
    // Take numbers greater than num_array[0]
    // Store numbers under greater_array
    // Of these numbers print the lowest
    for(j = 0; j < count; j++){
        if(num_array[j] > num_array[0]){
            greater_array[count2] = num_array[j];
            count2++;
        }
    }
    
    min = greater_array[0];
    
    for(k = 0; k < count2; k++){
        if(greater_array[k] < min){
            min = greater_array[k];
        }
    }
    printf("%d\n", min);
}

















