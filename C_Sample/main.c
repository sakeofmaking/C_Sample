/**********************************************************************
 * Title: Count File Lines
 *
 * Author: Nic La
 *
 * Purpose: write a program that takes
 * input : a file as an argument
 * output: counts the total number of lines.
 * for bonus, also count the number of words in the file.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/rzdwq/482012_challenge_37_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char IN_FILE[] = "/Users/thinklem/Dropbox/Embedded Systems/C_Sample/C_Sample/input.txt";

int main(){
    FILE *in_file_ptr;             // Input file
    char line[100];
    int line_count = 0;
    int word_count = 0;
    int i;
    
    // Open text file for reading
    in_file_ptr = fopen(IN_FILE, "r");
    if(in_file_ptr == NULL) {
        printf("Cannot open %s\n", IN_FILE);
        fclose(in_file_ptr);
        exit(8);
    }
    
    // Counts number of lines and words in text file
    // Assumption is that a space is between each word
    while(fgets(line, sizeof(line), in_file_ptr)){
        line_count++;
        for(i = 0; i < strlen(line); i++){
            if(line[i] == ' '){
                word_count++;
            }
        }
    }
    word_count += line_count;
    
    // Print number of lines in text file
    printf("Number of lines in file: %d\n", line_count);
    
    // Print number of words in text file
    printf("Number of words: %d\n", word_count);
    
    // Close text file
    fclose(in_file_ptr);
    return(0);
    
}





















