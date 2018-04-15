// ==================================================
// Problem  :   962B - Students in Railway Carriage
// Run time :   0.031 sec.
// Language :   C++14
// ==================================================


#include <bits/stdc++.h>
using namespace std;


const int MAXN = 2e5 + 3;


int main()
{
    //freopen("in.txt", "r", stdin);

    int n, a, b;
    char str[MAXN];

    scanf("%d %d %d %s", &n, &a, &b, str);

    int aa = 0, bb = 0, i = 0;

    while(i < n) {
        int consecutive_empty_seats = 0;

        while(str[i] != '*' and i < n) {
            ++consecutive_empty_seats;
            ++i;
        }

        ++i;

        int x1 = consecutive_empty_seats / 2;
        int x2 = consecutive_empty_seats - x1;

        if(a - aa <= b - bb) {
            aa += min(a - aa, x1);
            bb += min(b - bb, x2);
        }
        else {
            aa += min(a - aa, x2);
            bb += min(b - bb, x1);
        }
    }

    printf("%d\n", aa+bb);

    return 0;
}
