/**********************************************************************
 * Title: Phone Number
 *
 * Author: Nic La
 *
 * Often times in commercials, phone numbers contain letters so that they're 
 * easy to remember (e.g. 1-800-VERIZON). Write a program that will convert a 
 * phone number that contains letters into a phone number with only numbers and 
 * the appropriate dash. Click here to learn more about the telephone keypad.
 *
 * Example Execution: Input: 1-800-COMCAST Output: 1-800-266-2278
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/qit0h/352012_challenge_18_easy/
 *
 * Warning: Simplified code expects format #-###-LLLLLLL.
 *
 **********************************************************************/


#include <stdio.h>
#include <string.h>

int main()
{
    char line[100];
    int i;
    int j;
    int k;
    char letterpad[8][4] = {
        {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'},
        {'M', 'N', 'O'}, {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y', 'Z'}
    };
    char keypad[8] = {'2', '3', '4', '5', '6', '7', '8', '9'};
    int count = 0;
    
    printf("Enter phone number: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line)-1] = '\0';
    
    for(i = 0; i < strlen(line); i++){
        if((line[i] > 64) && (line[i] < 91)){
            for(j = 0; j < 8; j++){
                for(k = 0; k < 4; k++){
                    if(line[i] == letterpad[j][k]){
                        printf("%c", keypad[j]);
                        break;
                    }
                }
            }
            
            count++;
            if(count == 3){
                printf("-");
            }
        } else{
            printf("%c", line[i]);
        }
    }
}

















