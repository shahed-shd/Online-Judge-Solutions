#include <iostream>
#include <string>
using namespace std;

string weekDays[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

string monthNames[] = {"January", "February", "March", "April", "May", "June",
                    "July", "August", "September", "October", "November", "December"};

int daysInMonths[2][12] = {  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

bool isLeapYear(int y)
{
    if(y <= 1752) return (y % 4 == 0);
    else {
        if(y % 100 == 0)
            return (y % 400 == 0);
        else
            return (y % 4 == 0);
    }
}

bool isValid(int d, int m, int y)
{
    if(m > 12 || d > daysInMonths[isLeapYear(y)][m-1]) return false;

    if(y == 1752 && m == 9 && 3 <= d && d <= 13) return false;

    return true;
}

int solve(int d, int m, int y)
{
    int result = 0;   // 0 indicates Saturday. That is, 01/01/0001 was Saturday.

    if(y <= 1753) result += (y-1) * 365 + ((y-1)/4);
    else {
        result += (y-1) % 7;    // which comes from the expression ((y-1) * 365 ) % 7
                                // after applying the rule: (a * b) % m = ((a % m) * (b % m)) % m.
        result += ((y-1)/4 - (y-1)/100 + (y-1)/400) + 1752/100 - 1752/400;
    }

    bool is_leap_year = isLeapYear(y);

    for(int i = 1; i < m; ++i)
        result += daysInMonths[is_leap_year][i-1];

    result += d-1;

    if((y > 1752) || (y == 1752 && m > 9) || (y == 1752 && m == 9 && d > 13))
        result -= 11;

    result %= 7;

    return result;
}

int main()
{
    ios::sync_with_stdio(false);

    int d, m, y;

    while(cin >> m >> d >> y, d || m || y) {
        if(!isValid(d, m, y)) {
            cout << m << '/' << d << '/' << y << " is an invalid date.\n";
            continue;
        }

        cout << monthNames[m-1] << ' ' << d << ", " << y
            << " is a " << weekDays[solve(d, m, y)] << '\n';
    }

    return 0;
}
