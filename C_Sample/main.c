/**********************************************************************
 * Title: Challenge 11 Gaussian Algorithm
 *
 * Author: Nic La
 *
 * Purpose: The program should take three arguments. The first will be a day, 
 * the second will be month, and the third will be year. Then, your program should 
 * compute the day of the week that date will fall on.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/pwons/2192012_challenge_11_easy/
 *
 * Link: http://www.wikihow.com/Calculate-the-Day-of-the-Week
 *
 **********************************************************************/

#include <stdio.h>

int month_table[2][12] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5}
};
int century_table[2][5] = {
    {1600, 1700, 1800, 1900, 2000},
    {0, 5, 3, 1, 0}
};
char day_table1[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int day_table2[8] = {1, 2, 3, 4, 5, 6, 7, 0};

int main(){
    char line[100];
    int month_in = 0;
    int day_in = 0;
    int year_in = 0;
    
    printf("Enter date (mm/dd/yyyy): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d/%d/%d", &month_in, &day_in, &year_in);
    
#ifdef DEBUG
    printf("mm/dd/yyyy = %d/%d/%d\n", month_in, day_in, year_in);
#endif /* DEBUG */
    
    
}
