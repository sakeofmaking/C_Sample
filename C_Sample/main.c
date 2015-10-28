/**********************************************************************
 * Title: Challenge 13 Day of the Year
 *
 * Author: Nic La
 *
 * Purpose: Find the number of the year for the given date. For example, january 1st would be 1, and december 31st is 365.
 for extra credit, allow it to calculate leap years, as well.
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/pzo4w/2212012_challenge_13_easy/
 *
 **********************************************************************/

#include <stdio.h>

int main()
{
    //int days_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day_in = 0;
    int month_in = 0;
    int year_in = 0;
    char line[100];

    printf("Enter date (mm/dd/yyyy): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d/%d/%d", &month_in, &day_in, &year_in);
    
    if((year_in % 4) == 0){
        if((year_in % 100) == 0){
            if((year_in % 400) == 0){
                printf("%d is a leap year\n", year_in);
            } else{
                printf("%d is NOT a leap year\n", year_in);
            }
        } else{
            printf("%d is a leap year\n", year_in);
        }
    } else{
        printf("%d is NOT a leap year\n", year_in);
    }
    
}










