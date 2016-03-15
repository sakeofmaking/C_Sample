/**********************************************************************
 * Title: Alphabet Worth
 *
 * Author: Nic La
 *
 * Prompt source: https://www.reddit.com/r/dailyprogrammer/comments/tmnfq/5142012_challenge_52_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <string.h>
#define WORDS 6


void sort_words(char words_to_sort[WORDS][10])
{
    int i, j, k, m, n;
    int sum = 0;
    int num_array[WORDS];
    char temp[10];
    
    // Create int array based on word array
    for(i = 0; i < WORDS; i++)
    {
        for(j = 0; j < strlen(words_to_sort[i]); j++)
        {
            sum = sum + (words_to_sort[i][j] - 64);
            if((words_to_sort[i][j] >= 97) && (words_to_sort[i][j] <= 122))
            {
                sum -= 32;
            }
        }
        num_array[i] = sum;
        sum = 0;
    }
    
    // Sort word array based on int array
    for(k = 0; k < WORDS; k++)
    {
        for(m = 0; m < WORDS; m++)
        {
            if(num_array[k] < num_array[m])
            {
                num_array[k] = num_array[k] + num_array[m];
                num_array[m] = num_array[k] - num_array[m];
                num_array[k] = num_array[k] - num_array[m];
                
                strcpy(temp, words_to_sort[k]);
                strcpy(words_to_sort[k], words_to_sort[m]);
                strcpy(words_to_sort[m], temp);
            }
        }
    }
    
    // Print word array
    for(n = 0; n < WORDS; n++)
    {
        printf("%s\n", words_to_sort[n]);
    }
    
}

int main()
{
    char words_to_sort[WORDS][10] = {"Shoe", "Hat", "Cat", "Bat", "Pencil", "Coffee"};
    
    sort_words(words_to_sort);
    
    return 0;
}