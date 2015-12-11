/**********************************************************************
 * Title: Split List
 *
 * Author: Nic La
 *
 * Purpose: Input: a list
 * Output: Return the two halves as different lists.
 * If the input list has an odd number, the middle item can go to any of the list.
 * Your task is to write the function that splits a list in two halves.
 *
 * Warning: Must use format "element1,element2,element3,etc"
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/quli5/3132012_challenge_23_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>

char string[100];
char *string_ptr;

char *comma_char( char *string_ptr, char comma, int count){
    int ptr_count = 0;
    char *first_list_ptr;
    
    if(count < 2){
        count = 1;
    } else{
        count /= 2;
    }
    
    for(int i = 0; i < count; i++){
        while(*string_ptr != comma){
            if(*string_ptr == '\0'){
                return(NULL);
            }
            string_ptr++;
            ptr_count++;
        }
        string_ptr++;
        ptr_count++;
    }
    
    
    //Print first list
    strncpy(first_list_ptr, string_ptr - ptr_count, ptr_count - 1);
    printf("[%s]\n", first_list_ptr);
    
    return(string_ptr);     // Returns pointer to second list
}



int main(){
    int i;
    int element_count = 1;
    
    printf("Enter list: ");
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';
    
    // Function to count ',' to determine number of elements in list
    for(i = 0; i < strlen(string); i++){
        if(string[i] == ','){
            element_count++;
        }
    }
    
    // Print second list
    printf("[%s]\n", comma_char(string, ',', element_count));
 
}




















