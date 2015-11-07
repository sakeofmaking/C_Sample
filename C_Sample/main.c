/**********************************************************************
 * Title: Challenge 15: Right or Left Justify
 *
 * Author: Nic La
 *
 * Purpose: Write a program to indent a text file
 *
 **********************************************************************/


#include <stdio.h>
#include <stdlib.h>

const char IN_FILE[] = "/Users/thinklem/Dropbox/Embedded Systems/C_Sample/C_Sample/input.txt";
const char OUT_FILE[] = "/Users/thinklem/Dropbox/Embedded Systems/C_Sample/C_Sample/output.txt";

int main(){
    char line[100];                 /* store one line of file */
    FILE *in_file_ptr;              /* input file */
    FILE *out_file_ptr;             /* output file */
    
    /* open input file for reading */
    in_file_ptr = fopen(IN_FILE, "r");
    if(in_file_ptr == NULL) {
        printf("Cannot open %s\n", IN_FILE);
        fclose(in_file_ptr);
        exit(8);
    }
    
    /* open output file for writing */
    out_file_ptr = fopen(OUT_FILE, "w");
    if(out_file_ptr == NULL) {
        printf("Cannot open %s\n", OUT_FILE);
        fclose(out_file_ptr);
        exit(8);
    }
    
    /* indent and copy input to output */
    while(fgets(line, sizeof(line), in_file_ptr)){
        
        fprintf(out_file_ptr, "\t%s", line);

    }
    
    fclose(in_file_ptr);
    fclose(out_file_ptr);
    
    
    return(0);
}






