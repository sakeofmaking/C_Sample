/**********************************************************************
 * Title: QnA
 *
 * Author: Nic La
 *
 * Purpose: Write a program that prints a string from a list at random, 
 * expects input, checks for a right or wrong answer, and keeps doing it 
 * until the user types "exit". If given the right answer for the string 
 * printed, it will print another and continue on. If the answer is wrong, 
 * the correct answer is printed and the program continues.
 *
 * Bonus: Instead of defining the values in the program, the questions/answers 
 * is in a file, formatted for easy parsing.
 *
 * Example file:
 * 12 * 12?,144
 * What is reddit?,website with cats
 * Translate: hola,hello
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/rl24e/3302012_challenge_33_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>                 /* For string functions */
#include <stdlib.h>                 /* For random number generation */
#include <time.h>                   /* For seeding random number */
#include <stdbool.h>                /* For boolean variables */

const char QNA_LIST[] = "/Users/thinklem/Dropbox/Embedded Systems/C_Sample/C_Sample/QnA.txt";

// Generate random number within range
int randRange(int low, int high){
    return rand() % (high - low + 1) + low;
}

int main(){
    char line[100];                 /* Store input from user */
    char question[100];             /* Store individual Q from QnA list */
    char answer[100];               /* Store individual A from QnA list */
    int count = 0;                  /* Increment for new line in QnA list */
    bool ans = 0;
    int rand_num = 0;               /* Store random number */
    FILE *qna_list_ptr;             /* Input file */
    int i;
    
    srand((int)time(NULL));         /* Seed random number */
    
    while(1){
        // Print random question from text file
        // Open text file for reading
        qna_list_ptr = fopen(QNA_LIST, "r");
        if(qna_list_ptr == NULL) {
            printf("Cannot open %s\n", QNA_LIST);
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
        qna_list_ptr = fopen(QNA_LIST, "r");
        if(qna_list_ptr == NULL) {
            printf("Cannot open %s\n", QNA_LIST);
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
  
}






















