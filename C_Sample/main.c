/**********************************************************************
 * Title: Palindrome
 *
 * Author: Nic La
 *
 * Purpose: A Palindrome is a sequence that is the same in reverse as it is forward.
 * I.e. hannah, 12321. Your task is to write a function to determine whether a given 
 * string is palindromic or not.
 *
 * Bonus: Support multiple lines in your function to validate Demetri Martin's 224 word palindrome poem.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/r8a70/3222012_challenge_29_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char line[100];
    int count = 0;
    int i;
    bool palindrome = 0;
    
    printf("Enter string: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';
    
    // Determine if string is palindromic or not
    count = (int)strlen(line);
    for(i = 0; i < (strlen(line) / 2); i++){
        if(line[i] != line[strlen(line) - 1 - i]){
            palindrome = 0;
            break;
        } else{
            palindrome = 1;
        }
    }
    
    // Display if string is palindromic or not
    if(palindrome == 1){
        printf("%s is palindromic\n", line);
    } else{
        printf("%s is NOT palindromic\n", line);
    }

}





















