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
#include <stdbool.h>

int main()
{
    int days_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day_in = 0;
    int month_in = 0;
    int year_in = 0;
    char line[100];
    int i;
    int days_year = 0;
    bool leap_year = 0;

    // Ask for date
    printf("Enter date (mm/dd/yyyy): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d/%d/%d", &month_in, &day_in, &year_in);
    
    // Determine if leap year
    if((year_in % 4) == 0){
        if((year_in % 100) == 0){
            if((year_in % 400) == 0){
                leap_year = 1;
            } else{
                leap_year = 0;
            }
        } else{
            leap_year = 1;
        }
    } else{
        leap_year = 0;
    }
    if(leap_year == 1){
        days_month[1] = 29;
    }
    
    // Count day of the year
    for(i = 0; i < (month_in - 1); i++){
        days_year += days_month[i];
    }
    days_year += day_in;
    
    
    printf("Day of the year = %d\n", days_year);
}










