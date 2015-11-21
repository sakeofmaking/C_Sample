/**********************************************************************
 * Title: Triangle of Stars
 *
 * Author: Nic La
 *
 * Purpose: write an application which will print a triangle of stars of 
 * user-specified height, with each line having twice as many stars as the 
 * last. sample output:
 * @
 * @@
 * @@@@
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/qheeu/342012_challenge_17_easy/
 *
 **********************************************************************/


#include <stdio.h>

int main()
{
    char line[100];
    char star = '*';
    int height = 0;
    int i;
    int j;
    
    printf("Enter height: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &height);
    
    for(i = 0; i < height; i++){
        for(j = 0; j < i + 1; j++){
            printf("%c", star);
        }
        printf("\n");
    }
    
}

















