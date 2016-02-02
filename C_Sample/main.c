/**********************************************************************
 * Title: Caesar Cipher
 *
 * Author: Nic La
 *
 * Prompt source: https://www.reddit.com/r/dailyprogrammer/comments/t33vi/522012_challenge_47_easy/
 *
 * Requirements:
 * Ask user for text to shift
 * Ask how much to shift it by
 *      Range that it can be shifted by 0 - 26
 * Shift text by amount to shift
 **********************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[1000];
    char text2shift[1000];
    int shift_amount = 0;
    int i;
    int temp = 0;
    
    printf("Enter text to code: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';
    strcpy(text2shift, line);
    
    do
    {
        printf("Enter amount to shift text by: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &shift_amount);
    }while(shift_amount < 0 || shift_amount > 26);
    
    for(i =0; i < strlen(text2shift); i++)
    {
        temp = text2shift[i];
        
        // If past Z, wrap around
        if((temp >= 65) && (temp <= 90))
        {
            temp += shift_amount;
            if(temp > 90)
            {
                temp -= 26;
            }
        }
        
        // If past z, wrap around
        if((temp >= 97) && (temp <= 122))
        {
            temp += shift_amount;
            if(temp > 122)
            {
                temp -= 26;
            }
        }
        
        text2shift[i] = temp;
        
        printf("%c", text2shift[i]);
    }
    
    return(0);
}












