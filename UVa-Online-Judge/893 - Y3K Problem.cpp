// ==================================================
// Problem  :   893 - Y3K Problem
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;


const int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


inline bool is_leap_year(int y)
{
    return bool(y % ((y % 100 == 0)? 400 : 4) == 0);

}


inline int leap_year_count(int y)
{
    return (y/4 - y/100 + y/400);
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int a, dd, mm, yyyy;

    while(scanf("%d %d %d %d", &a, &dd, &mm, &yyyy), a or dd or mm or yyyy) {
        // Go to the last day of previous year of yyyy.
        // Convert dd and mm into days. And add them to a.

        for(int i = 1; i < mm; ++i)
            a += monthDays[i];

        if(is_leap_year(yyyy) and mm > 2)
            ++a;

        a += dd;

        --yyyy;

        // Now, reduce a by adding years to yyyy.

        do {
            int y = a / 366;
            a %= 366;

            int ly = leap_year_count(yyyy + y) - leap_year_count(yyyy);
            a += y - ly;
            yyyy += y;
        } while(a >= 366);

        // Now, convert the remaining days into month and day.

        if(a) {
            ++yyyy;
            mm = 1;

            while(a > monthDays[mm]) {
                a -= monthDays[mm];
                ++mm;
            }

            if(is_leap_year(yyyy) and mm > 2) {
                --a;
            }

            if(a <= 0) {
                --mm;
                dd = monthDays[mm] + (mm == 2 and is_leap_year(yyyy)) + a;
            }
            else {
                dd = a;
            }
        }
        else {
            mm = 12, dd = 31;
        }

        printf("%d %d %d\n", dd, mm, yyyy);
    }

    return 0;
}
