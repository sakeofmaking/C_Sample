/**********************************************************************
 * Title: Challenge 16: String Subtraction
 *
 * Author: Nic La
 *
 * Purpose: Write a function that takes two strings and removes from the 
 * first string any character that appears in the second string. For instance, 
 * if the first string is “Daily Programmer” and the second string is “aeiou ” 
 * the result is “DlyPrgrmmr”.
 * note: the second string has [space] so the space between "Daily Programmer" is removed
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/q8aom/2272012_challenge_16_easy/
 *
 **********************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void *minus(char *string1_ptr, char *string2_ptr){
    int count1 = (int)strlen(string1_ptr);
    int count2 = (int)strlen(string2_ptr);
    bool match;
    
    for(string1_ptr = &string1_ptr[0]; string1_ptr < &string1_ptr[strlen(string1_ptr)]; string1_ptr++){
        match = 0;
        for(string2_ptr = &string2_ptr[0]; string2_ptr < &string2_ptr[strlen(string2_ptr)]; string2_ptr++){
            if(*string1_ptr == *string2_ptr){
                match = 1;
            }
        }
        string2_ptr -= count2;
        if(match == 0){
            printf("%c", *string1_ptr);
        }
    }
    string1_ptr -= count1;
    
    return(0);
}


int main(){
    char string1[100];
    char string2[100];
    
    printf("Enter string 1: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strlen(string1) - 1] = '\0';
    
    printf("Enter string 2: ");
    fgets(string2, sizeof(string2), stdin);
    string2[strlen(string2) - 1] = '\0';
    
    minus(string1, string2);
    
}














