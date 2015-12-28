/**********************************************************************
 * Title: Two Larger Numbers
 *
 * Author: Nic La
 *
 * Purpose: A very basic challenge:
 * In this challenge, the
 * input is are : 3 numbers as arguments
 * output: the sum of the squares of the two larger numbers.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/rmmn8/3312012_challenge_34_easy/
 *
 **********************************************************************/

// Ask for 3 numbers
    // Want format "%d %d %d"
// Identify the two larger numbers
// (num1 * num1) + (num2 * num2)

#include <stdio.h>

int main(){
    char line[100];
    int num[3];
    int i, j;
    
    // Accept 3 numbers as arguments
    printf("Enter 3 numbers: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d %d", &num[0], &num[1], &num[2]);
    
    // Identify the two larger numbers
    // Reorder from largest to smallest
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(num[i] > num[j]){
                num[i] += num[j];
                num[j] = num[i] - num[j];
                num[i] -= num[j];
            }
        }
    }
    
    // Take the sum of the squares of the two larger numbers
    printf("num1^2 + num2^2 = %d\n", (num[0] * num[0]) + (num[1] * num[1]));
    
}






















