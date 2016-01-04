/**********************************************************************
 * Title: 1000 Lockers Problem
 *
 * Author: Nic La
 *
 * Purpose: 1000 Lockers Problem.
 * In an imaginary high school there exist 1000 lockers labelled 1, 2, ..., 1000.
 * All of them are closed. 1000 students are to "toggle" a locker's state. 
 * The first student toggles all of them * The second one toggles every other 
 * one (i.e, 2, 4, 6, ...) * The third one toggles the multiples of 3 (3, 6, 9, ...) 
 * and so on until all students have finished.
 * To toggle means to close the locker if it is open, and to open it if it's closed.
 * How many and which lockers are open in the end?
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/ruiob/452012_challenge_36_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(){
    bool locker[1000];
    int i, j, k, m;
    
    // Initialize all lockers to 0 to represent closed
    for(i = 0; i < 1000; i++){
        locker[i] = 0;
    }
    
    // Each student toggles locker multiples of their reprective number
    for(j = 1; j <= 1000; j++){
        for(k = 1; k <= 1000; k++){
            // For multiples of student j, toggle locker k
            if(k % j == 0){
                locker[k - 1] = !locker[k - 1];
            }
        }
    }
    
    // Print open lockers
    for(m = 0; m < 1000; m++){
        if(locker[m] == 1){
            printf("[%d]", m + 1);
        }
    }
}






















