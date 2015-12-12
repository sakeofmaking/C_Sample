/**********************************************************************
 * Title: Majority Wins
 *
 * Author: Nic La
 *
 * Purpose: In an election, the person with the majority of the votes is 
 * the winner. Sometimes due to similar number of votes, there are no winners.
 * Your challenge is to write a program that determines the winner of a vote, 
 * or shows that there are no winners due to a lack of majority.
 * 
 * Detail: Lack of majority means no 50% of the voters agree on a single candidate
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/qxuug/3152012_challenge_25_easy/
 *
 **********************************************************************/

#include <stdio.h>

int main(){
    char line[100];
    int num_candidates = 0;
    int indv_votes[100];
    int total_votes = 0;
    int winner = 0;
    
    // Ask for number of candidates
    printf("Enter number of candidates: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &num_candidates);
    
    // Ask for number of votes for each candidate
    for(int i = 1; i <= num_candidates; i++){
        printf("Enter votes candidate %d received: ", i);
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &indv_votes[i]);
        total_votes += indv_votes[i];
    }
    
    // Determine if any candidate received a majority
    for(int j = 1; j <= num_candidates; j++){
        if(indv_votes[j] > (total_votes / 2)){
            winner = j;
            break;
        }
    }
    
    // Print the winner
    if(winner != 0){
        printf("The winner is candidate %d!\n", winner);
    } else{
        printf("There is no winner due to lack of majority\n");
    }
}




















