/**********************************************************************
 * Title: Duplicates
 *
 * Author: Nic La
 *
 * Purpose: you have a string "ddaaiillyypprrooggrraammeerr". We want to 
 * remove all the duplicates and put them in a separate string.
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>

char *remove_char(char *string_ptr, char duplicate){
    char *temp_string_ptr = string_ptr;
    char string[100];
    int count = 0;
    
    for(int i = 0; i < 2; i++){
        while(*string_ptr != duplicate){
            if(*string_ptr == '\0'){
                return(NULL);
            }
            string_ptr++;
            count++;
        }
        string_ptr++;
        count++;
    }
    
    temp_string_ptr[count - 1] = '\0';
    strcpy(string, string_ptr);
    strcat(temp_string_ptr, string);
    
    return(temp_string_ptr);
}

int main(){
    int i, j;
    int count = 0;
    char string1[100];
    char string2[100];
    char temp_string[100];
    
    printf("Enter string: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strlen(string1) - 1] = '\0';
    
    for(i = 0; i < strlen(string1); i++){
        for(j = 0; j < strlen(string1); j++){
            if((string1[i] == string1[j]) && (i != j)){
                // Copy duplicate char into string2[]
                string2[count] = string1[j];
                
                // Remove duplicate char from string1[]
                strcpy(temp_string, remove_char(string1, string2[count]));
                strcpy(string1, temp_string);
                count++;
            }
        }
    }
    
    printf("%s\n%s\n", string1, string2);
}





















