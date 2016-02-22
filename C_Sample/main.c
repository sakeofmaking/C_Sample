/**********************************************************************
 * Title: A New Car
 *
 * Author: Nic La
 *
 * Prompt source: https://www.reddit.com/r/dailyprogrammer/comments/tb2h0/572012_challenge_49_easy/
 *
 **********************************************************************/

// The Plan
// Create 200 (GAMES) games shows
    // Define 3 doors
    // Randomly assign each door a car, goat, goat
// Play the game
    // First 100 games, player randomly picks a door and doesn't switch
        // Count number of wins and print
    // Second 100 games, player randomly picks a door, one goat door is opened (removed), player then switches
        // Pick one of the two 0s not picked by the player and remove it by assigning it a 3 (will have 0, 1, 3 combination)
        // Switch the player's choice ignoring the 3 (if player picked 1, switch to 0; if player picked 0, switch to 1)
        // Count number of wins and print


#include <stdio.h>
#include <time.h>   // To seed rand()
#include <stdlib.h> // For rand()

#define GAMES 20000   // Number of games to play

// Return random number between low and high
int randRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

// First 100 games: No switch choice
int firstGame(int doorArray[3][GAMES])
{
    int winCount = 0;
    int i, j;
    int chosenDoor = 0;
    
    for(i = 0; i < GAMES/2; i++)
    {
        chosenDoor = randRange(0, 2);
        for(j = 0; j < 3; j++)
        {
            if((j == chosenDoor) && (doorArray[j][i] == 1))
            {
                winCount++;
            }
        }
    }
    
    return(winCount);
}

// Second 100 games: Switch choice
int secondGame(int doorArray[3][GAMES])
{
    int winCount = 0;
    int i, j;
    int chosenDoor = 0;
    int openDoor = 0;
    
    for(i = GAMES/2; i < GAMES; i++)
    {
        chosenDoor = randRange(0, 2);
        for(j = 0; j < 3; j++)
        {
            if((doorArray[j][i] == 0) && (j != chosenDoor) && (openDoor == 0))
            {
                doorArray[j][i] = 3;
                openDoor = 1;
            }
        }
        if(doorArray[chosenDoor][i] == 0){
            winCount++;
        }
        openDoor = 0;
    }
    
    return(winCount);
}


int main()
{
    
    // Seed rand()
    srand((int)time(NULL));
    
    // Define 3 Doors Array and randomly assign each door car, goat, goat
    // car = 1
    // goat = 0
    int doorArray[3][GAMES];
    int i, j;
    int state = 0;
    for(i = 0; i < GAMES; i++)
    {
        state = randRange(0, 2);
        for(j = 0; j < 3; j++)
        {
            if(j == state)
            {
                doorArray[j][i] = 1;
            }
            else
            {
                doorArray[j][i] = 0;
            }
        }
    }
    
    printf("Wins out of %d no switch games = %d\n", GAMES/2, firstGame(doorArray));
    printf("Wins out of %d switch games = %d\n", GAMES/2, secondGame(doorArray));
    
    return(0);
}








