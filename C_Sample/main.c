/**********************************************************************
 * Title: Prime Number
 *
 * Author: Nic La
 *
 * Purpose: To determine if a number entered by the user is a prime number.
 *
 **********************************************************************/


#include <stdio.h>
#include <string.h>

char line[100];
int num = 0;
int i = 0;
int count = 0;
int modular = 0;

int main()
{
    printf("Enter number in question: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &num);
    
    if(num <= 1){
        printf("%d is NOT a prime number\n", num);
    } else {
        for(i=2;i<num;i++){
            modular = num % i;
            if(modular == 0){
                printf("%d is NOT a prime number\n", num);
                count++;
                break;
            }
        }
        if(count == 0){
            printf("%d is a prime number\n", num);
        }
    }
}

















