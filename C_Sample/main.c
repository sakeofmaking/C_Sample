/**********************************************************************
 * Title: Challenge 11 Day of the Week
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
//#define DDEBUG

int month_table[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};     /* corresponds to months 1, 2, 3, ..., 12 */
int century_table[5] = {0, 5, 3, 1, 0};                         /* corresponds to centuries 1600, 1700, 1800, 1900, 2000 */
char day_table[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main(){
    char line[100];
    int month_in = 0;
    int day_in = 0;
    int year_in = 0;
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    
    printf("Enter date (mm/dd/yyyy): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d/%d/%d", &month_in, &day_in, &year_in);
    
#ifdef DDEBUG
    printf("mm/dd/yyyy = %d/%d/%d\n", month_in, day_in, year_in);
    printf("day_in + month_table = %d\n", day_in + month_table[month_in - 1]);
#endif /* DDEBUG */
    
    /* Step 1: Add day and month from table */
    result1 = day_in + month_table[month_in - 1];
    if(result1 > 6){
        result1 = result1 % 7;
    }

#ifdef DDEBUG
    printf("result1 = %d\n", result1);
#endif /* DDEBUG */
    
    /* Step 2: Take last two digits of the year */
    result2 = year_in % 100;
    result2 = (result2 % 28) + (result2 / 4) + century_table[((year_in - result2) / 100) - 16];
    
    /* If Jan or Feb and leap year subtract 1 from result2 */
    
#ifdef DDEBUG
    printf("result2 = %d\n", result2);
#endif /* DDEBUG */
    
    /* Step 3: Compare result3 with day_table */
    result3 = result1 + result2;
    if(result3 > 6){
        result3 = result3 % 7;
    }
    if(result3 == 0){
        result3 = 7;
    }
    printf("Day of the week = %s\n", day_table[result3 - 1]);
    
#ifdef DDEBUG
    printf("result3 = %d\n", result3);
#endif /* DDEBUG */
    
}











