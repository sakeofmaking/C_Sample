/**********************************************************************
 * Title: Challenge 7 Morse Code
 *
 * Author
 *
 * Purpose: Write a program that can translate Morse code in the format of ...---...
 * A space and a slash will be placed between words. ..- / --.-
 *
 * Bonus: Add the capability of going from a string to Morse code.
 *
 * Super-bonus: if your program can flash or beep the Morse.
 *
 * Example:
 * .... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. /
 * --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. .
 * -. --. . ... / - --- -.. .- -.--
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/pr2xr/2152012_challenge_7_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>

char morse_key[37][10] = { "/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };
char char_key[37] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


int main(){
    char encoded[] = ".... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--";
    int count;
    char temp[10];
    int i;
    int j;
    int k;
    int m;

    for(m = 0; m < 55; m++){
        /* count the number of characters in morse symbol of interest */
        /* ex. "...." has 4 characters */
        count = 0;
        while(encoded[count] != ' '){
            count++;
        }
    
        /* store morse symbol of interest in temp */
        for(k = 0; k < count; k++){
            temp[k] = encoded[k];
        }
        temp[k] = '\0';
    
        /* compare morse symbol of interest against morse_key */
        /* print corresponding char_key */
        for(i = 0; i < 37; i++){
            if(strcmp(temp, morse_key[i]) == 0){
                printf("%c", char_key[i]);
                break;
            }
        }
    
        /* shift encoded message by one morse symbol */
        for(j = 0; j < strlen(encoded); j++){
            encoded[j] = encoded[j + count + 1];
        }
    }
    
}
