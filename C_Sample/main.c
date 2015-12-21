/**********************************************************************
 * Title: Base 26
 *
 * Author: Nic La
 *
 * Purpose: Write a function that takes two base-26 numbers in which digits 
 * are represented by letters with A=0, B=1, … Z=25 and returns their product 
 * using the same notation. As an example, CSGHJ × CBA = FNEUZJA. Your task 
 * is to write the base-26 multiplication function. Try to be very efficient 
 * in your code!
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/rg1vv/3272012_challenge_31_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h> /* For string functions */
#include <math.h> /* For pow function */

int main()
{
    char line[100];
    int temp = 0;
    int decimal1 = 0;
    int decimal2 = 0;
    int multiple = 0;
    int invert[100];
    int count = 0;
    int i;
    
    // Store first base-26 number
    printf("Enter first base-26 number: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';
    
    // Necessary because strlen(line) changes inside the for loop
    temp = (int)strlen(line);
    
    for(i = 0; i < temp; i++){
        // If lowercase, make uppercase
        if((line[i] >= 97) && (line[i] <= 122)){
            line[i] -= 32;
        }
        
        // Convert to integer
        line[i] -= 65;
        
        // Convert to decimal
        decimal1 += line[i] * pow(26, temp - 1 - i);
    }
    
    // Store second base-26 number
    printf("Enter second base-26 number: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0';
    temp = (int)strlen(line);
    for(i = 0; i < temp; i++){
        if((line[i] >= 97) && (line[i] <= 122)){
            line[i] -= 32;
        }
        line[i] -= 65;
        decimal2 += line[i] * pow(26, temp - 1 - i);
    }
    
    // Perform decimal multiplication
    multiple = decimal1 * decimal2;
    
    // Convert result to base-26
    // Store backwards in int array
    while(multiple != 0){
        invert[count] = multiple % 26;
        multiple /= 26;
        count++;
    }
    
    printf("Multiple = ");
    // Represent result as base-26
    // Print array in correct order
    for(i = count; i > 0; i--){
        invert[i - 1] += 65;
        printf("%c", invert[i - 1]);
        
    }

}





















