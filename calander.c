```c
#include <stdio.h>

// Function to calculate the Doomsday number for a given century
int getDoomsdayCenturyNumber(int year) {
    int centuryDoomsday = 5;
    for(int i = 1100; i <= year; i += 100) {
        if (centuryDoomsday == 0) {
            centuryDoomsday = 5;
        } else if (centuryDoomsday == 3) {
            centuryDoomsday -= 1;
        } else {
            centuryDoomsday -= 2;
        }
    }  
    return centuryDoomsday;
}

// Function to get the Doomsday date of the given month and year
int getDoomsdayMonthDate(int month, int year) {
    switch(month) {
        case 1:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 4; // Leap year
            else return 3; // Non-leap year
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 29; // Leap year
            else return 28; // Non-leap year
        case 3: return 14;
        case 4: return 4;
        case 5: return 9;
        case 6: return 6;
        case 7: return 11;
        case 8: return 8;
        case 9: return 5;
        case 10: return 10;
        case 11: return 7;
        case 12: return 12;
        default: return -1; // Invalid month
    }
}

// Function to calculate the day code for the first date of the month
int getDayCodeOfFirstDate(int doomsdayOfYear, int doomsdayMonthDate) {
    for (int i = doomsdayMonthDate; i > 1; i--) {
        if (doomsdayOfYear == 0) {
            doomsdayOfYear = 6;
        } else {
            doomsdayOfYear--;
        }
    }
    return doomsdayOfYear;
}

// Main function to calculate the day code for the first day of a given month and year
int calculateFirstDayCode(int year, int month) {
    int century = (year / 100) * 100;
    int centuryDoomsdayNumber = getDoomsdayCenturyNumber(century);
    int yearPart = year - century;
    int sum = centuryDoomsdayNumber + yearPart + (yearPart / 4);
    int doomsdayOfYear = sum % 7;
    int doomsdayMonthDate = getDoomsdayMonthDate(month, year);
    return getDayCodeOfFirstDate(doomsdayOfYear, doomsdayMonthDate);
}

int main() {   
    int year;
    int MonthLastDate[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    printf("Enter the year [After 1500] :\n");
    scanf("%d", &year);
    
    printf("\n\n\nWelcome to the Year \n\t%d\n\n", year);
    
    // Adjust February days for leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        MonthLastDate[1] = 29;
    }
    
    int MonthFirstDay[12];
    for (int i = 0; i < 12; i++) {
        MonthFirstDay[i] = calculateFirstDayCode(year, i + 1);
    }
    
    char *Month[] = {"JAN","FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    
    for (int L = 0; L < 12; L++) {
        for (int i = 0; i < 20; i++) printf("-"); 
        printf("\n\t%s\n", Month[L]);
        for (int i = 0; i < 20; i++) printf("-"); 
        printf("\n");
        
        printf(" S  M  T  W  T  F  S \n\n");
    
        for (int MonthFirstDate = 1, i = 1; 1; i++) {
            if (i <= MonthFirstDay[L]) {
                printf("   ");
            } else {
                printf("%2d ", MonthFirstDate);
                MonthFirstDate++;
                if (i % 7 == 0) printf("\n");
            }
            if (MonthFirstDate == MonthLastDate[L] + 1) break;
        }
        printf("\n\n");
    }
    printf("<------- END ------>");
    return 0;
}


```
