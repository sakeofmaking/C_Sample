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
    
    
    

    
    
    
    
    
    
    
    
    
    
    
 /*
    char line[100];                 //Store input from user
    char question[100];             / Store individual Q from QnA list
    char answer[100];               / Store individual A from QnA list
    int count = 0;                  / Increment for new line in QnA list
    bool ans = 0;
    int rand_num = 0;               / Store random number
    FILE *qna_list_ptr;             / Input file
    int i;
    
    while(1){
        // Print random question from text file
        // Open text file for reading
        qna_list_ptr = fopen(IN_FILE, "r");
        if(qna_list_ptr == NULL) {
            printf("Cannot open %s\n", IN_FILE);
            fclose(qna_list_ptr);
            exit(8);
        }
        
        // Counts number of lines in text file
        count = 0;
        while(fgets(line, sizeof(line), qna_list_ptr)){
            count++;
        }
        
        // Generate random number
        rand_num = randRange(1, count);
        
        fclose(qna_list_ptr);
        
        // Open text file for reading
        qna_list_ptr = fopen(IN_FILE, "r");
        if(qna_list_ptr == NULL) {
            printf("Cannot open %s\n", IN_FILE);
            fclose(qna_list_ptr);
            exit(8);
        }
        
        // Print Q
        count = 1;
        while(fgets(line, sizeof(line), qna_list_ptr) && (rand_num != count)){
            count++;
        }
        fclose(qna_list_ptr);
        
        // Separate line into Q and A
        ans = 0;
        count = 0;
        for(i = 0; i < strlen(line); i++){
            if((line[i] != '?') && (ans == 0)){
                question[i] = line[i];
            } else if(line[i] == '?'){
                question[i] = line[i];
                question[i + 1] = '\0';
                ans = 1;
            } else if(ans == 1){
                answer[count] = line[i];
                count++;
            }
        }
        answer[count - 1] = '\0';
        printf("%s\n", question);
        
        
        // Accept input
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0';
        
        // Check for exit
        if(strcmp(line, "exit") == 0){
            exit(8);
        }
        
        // Compare input with answer
        if(strcmp(line, answer) != 0){
            printf("%s\n", answer);
        }
        
    }
    */
}





















