/**********************************************************************
 * Title: Bottles of Beer
 *
 * Author: Nic La
 *
 * Purpose: Write a program that prints out the lyrics for "Ninety-nine 
 * bottles of beer", "Old McDonald had a farm" or "12 days of Christmas".
 * If you choose "Ninety-nine bottles of beer", you need to spell out the 
 * number, not just write the digits down. It's "Ninety-nine bottles of 
 * beer on the wall", not "99 bottles of beer"! 
 *
 * Prompt: https://www.reddit.com/r/dailyprogrammer/comments/sobna/4232012_challenge_42_easy/
 * Number to english: https://github.com/sakeofmaking/Cpp_Sample/blob/0fc91b50a81af8031b98358158393c03b8e85801/Cpp_Sample/main.cpp
 *
 **********************************************************************/

#include <stdio.h>

int main(){
    int i, j;
    char under_twenty[20][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
        "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char twenty_above[8][20] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    for(i = 99; i > 2; i--){
        /****** ## bottles of beer on the wall, ## bottles of beer. ******/
        /****** Take one down and pass it around ******/
        if(i < 20){
            // Number is less than twenty
            under_twenty[i][0] -= 32;
            printf("%s", under_twenty[i]);
            under_twenty[i][0] += 32;
            printf(" bottles of beer on the wall, ");
            printf("%s", under_twenty[i]);
            printf(" bottles of beer. Take one down and pass it around, ");
            j = i - 1;
        } else{
            // Number is greater than or equal twenty
            twenty_above[(i / 10) - 2][0] -= 32;
            printf("%s", twenty_above[(i / 10) - 2]);
            twenty_above[(i / 10) - 2][0] += 32;
            if(i - (i / 10 * 10) != 0){
                printf("-%s", under_twenty[i - (i / 10 * 10)]);
            }
            printf(" bottles of beer on the wall, ");
            printf("%s", twenty_above[(i / 10) - 2]);
            if(i - (i / 10 * 10) != 0){
                printf("-%s", under_twenty[i - (i / 10 * 10)]);
            }
            printf(" bottles of beer. Take one down and pass it around, ");
            j = i - 1;
        }
        
        /****** ## bottles of beer on the wall ******/
        if(j < 20){
            // Number is less than twenty
            printf("%s", under_twenty[j]);
            printf(" bottles of beer on the wall. ");
        } else{
            // Number is greater than or equal twenty
            printf("%s", twenty_above[(i / 10) - 2]);
            if(j - (j / 10 * 10) != 0){
                printf("-%s", under_twenty[j - (j / 10 * 10)]);
            }
            printf(" bottles of beer on the wall. ");
        }
        
    }
    
    /****** Last few lines ******/
    printf("Two bottles of beer on the wall, two bottles of beer. ");
    printf("Take one down and pass it around, one bottle of beer on the wall. ");
    printf("One bottle of beer on the wall, one bottle of beer. ");
    printf("Take one down and pass it around, no more bottles of beer on the wall. ");
    printf("No more bottles of beer on the wall, no more bottles of beer. ");
    printf("Go to the store and buy some more, 99 bottles of beer on the wall. ");
    
    return(0);
}




















