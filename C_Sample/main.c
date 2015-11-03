/**********************************************************************
 * Title: Challenge 14
 *
 * Author: Nic La
 *
 * Purpose: Input: list of elements and a block size k or some other variable of your choice
 * Output: return the list of elements with every block of k elements reversed, starting from the beginning of the list.
 * For instance, given the list 12, 24, 32, 44, 55, 66 and the block size 2, the result is 24, 12, 44, 32, 66, 55.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/q2v2k/2232012_challenge_14_easy/
 *
 **********************************************************************/


#include <stdio.h>

// fails if len is not evenly divisible by k
void block_reversed(int block[],int len, int k){
    int i, j;
    int x = 0;
    
    for(j = 0; j < (len / k); j++){
        for(i = k - 1; i >= 0; i--){
            printf("[%d]", block[i + x]);
        }
        x += k;
    }
}


int main()
{
    int test_block[] = { 12, 24, 32, 44, 55, 66 };
    int len = 6;
    int k = 2;
    
    block_reversed(test_block,len, k);
    
}










