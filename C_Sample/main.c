/**********************************************************************
 * Title: ASCII Decoration Banner
 *
 * Author: Nic La
 *
 * Purpose: Write a program that will accept a sentence as input and then 
 * output that sentence surrounded by some type of an ASCII decoratoin banner.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/shp28/4192012_challenge_41_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>

#define Stars printf("****"); for(i = 0; i < strlen(line); i++){printf("*");}
#define Buffer printf("\n* "); for(i = 0; i < strlen(line); i++){printf(" ");} printf(" *\n");

int main()
{
    char line[100];
    int i;
    
    printf("Enter sentence: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';
    
    Stars
    Buffer
    printf("* %s *", line);
    Buffer
    Stars
    
    return(0);
}




















