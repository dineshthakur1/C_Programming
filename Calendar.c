#include <stdbool.h>
#include <stdio.h>

bool is_leap_year(int year) {
    bool leap_year = false;

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                leap_year = true;
            } else {
                leap_year = false;
            }
        } else {
            leap_year = true;
        }

    } else {
        leap_year = false;
    }
    return leap_year;
}

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
    while (days_left_to_add > 0) {
        if (*mm == 1 || *mm == 3 || *mm == 5 || *mm == 7 || *mm == 8 ||
            *mm == 10) {
            if (days_left_to_add + *dd > 31) {
                *mm += 1;
                days_left_to_add -= (31 - *dd);
                *dd = 0;
            } else {
                *dd += days_left_to_add;
                days_left_to_add -= *dd;
            }
        } else if (*mm == 4 || *mm == 6 || *mm == 9 || *mm == 11) {
            if (days_left_to_add + *dd > 30) {
                *mm += 1;
                days_left_to_add -= (30 - *dd);
                *dd = 0;
            } else {
                *dd += days_left_to_add;
                days_left_to_add -= *dd;
            }
        } else if (*mm == 12) {
            if (days_left_to_add + *dd > 31) {
                *mm = 1;
                *yy += 1;
                days_left_to_add -= (31 - *dd);
                *dd = 0;
            } else {
                *dd += days_left_to_add;
                days_left_to_add -= *dd;
            }
        } else if (*mm == 2) {
            if (is_leap_year(*yy)) {
                if (days_left_to_add + *dd > 29) {
                    *mm += 1;
                    days_left_to_add -= (29 - *dd);
                    *dd = 0;
                } else {
                    *dd += days_left_to_add;
                    days_left_to_add -= *dd;
                }
            } else {
                if (days_left_to_add + *dd > 28) {
                    *mm += 1;
                    days_left_to_add -= (28 - *dd);
                    *dd = 0;
                } else {
                    *dd += days_left_to_add;
                    days_left_to_add -= *dd;
                }
            }
        }
    }
}

int main() {
    int mm, dd, yy, days_left_to_add;
    printf(
        "Enter Date and Days to add in this format:(mm dd yyyy day_to_add)\t");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    printf("%d/%d/%d", mm, dd, yy);
}