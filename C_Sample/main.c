/**********************************************************************
 * Title: Leap Year
 *
 * Author: Nic La
 *
 * Purpose: Write a program that accepts a year as input and outputs the 
 * century the year belongs in (e.g. 18th century's year ranges are 1701 
 * to 1800) and whether or not the year is a leap year. Pseudocode for 
 * leap year can be found here.
 *
 * Sample run:
 * Enter Year: 1996
 * Century: 20
 * Leap Year: Yes
 * Enter Year: 1900
 * Century: 19
 * Leap Year: No
 *
 * Link: https://www.reddit.com/r/dailyprogrammer/comments/r0r3h/3172012_challenge_27_easy/
 *
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    char line[100];
    int year_in = 0;
    bool leap_year = 0;
    int century = 0;
    
    // Ask for date
    printf("Enter Year: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &year_in);
    
    // Determine century
    if((year_in % 100) == 0){
        century = year_in / 100;
    } else{
        century = (year_in / 100) + 1;
    }
    
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
    
    // Print
    printf("Century: %d\n", century);
    if(leap_year == 1){
        printf("Leap Year: Yes\n");
    } else{
        printf("Leap Year: No\n");
    }
}





















