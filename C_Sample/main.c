/**********************************************************************
 * Title: Character Count
 *
 * Author: Nic La
 *
 * Purpose: To count the number of characters inside a text file.
 *
 **********************************************************************/


#include <stdio.h>
const char FILE_NAME[] = "/Users/thinklem/Dropbox/Embedded Systems/C_Sample/C_Sample/input.txt";
#include <stdlib.h>

int main(){
    int count = 0;          /* number of characters seen */
    FILE *in_file;          /* input file */
    
    /* character of EOF flag from input */
    int ch;
    
    in_file = fopen(FILE_NAME, "r");
    if(in_file == NULL) {
        printf("Cannot open %s\n", FILE_NAME);
        exit(8);
    }
    
    while(1){
        ch = fgetc(in_file);
        if(ch == EOF){
            break;
        }
        ++count;
    }
    printf("Number of characters in %s is %d\n", FILE_NAME, count);
    
    fclose(in_file);
    return(0);
}

















