/**********************************************************************
 * Title: Right Triangle
 *
 * Author: Nic La
 *
 * Purpose: Write a program that will take a number and print a right 
 * triangle attempting to use all numbers from 1 to that number.
 *
 * Sample Run:
 * Enter number: 10
 * Output:
 * 7 8 9 10
 * 4 5 6
 * 2 3
 * 1
 * Enter number: 6
 * Output:
 * 4 5 6
 * 2 3
 * 1
 * Enter number: 3
 * Output:
 * 2 3
 * 1
 * Enter number: 12
 * Output:
 * 7 8 9 10
 * 4 5 6
 * 2 3
 * 1
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/rr4y2/432012_challenge_35_easy/
 *
 **********************************************************************/

#include <stdio.h>

int main(){
    char line[100];
    int num = 0;
    int temp = 1;
    int i = 2;
    int j;
    
    // Store input as num
    printf("Enter number: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &num);
    
    // Determine highest number within input that satisfies the right triangle
    while(temp < num){
        temp += i;
        i++;
    }
    if(temp > num){
        i--;
        temp -= i;
    }
    num = temp;
    
    printf("Output:\n");
    
    // Print right triangle
    do{
        for(j = i - 2; j >= 0; j--){
            printf("%d ", num - j);
        }
        printf("\n");
        i--;
        num -= i;
    } while(num > 0);
    
}






















