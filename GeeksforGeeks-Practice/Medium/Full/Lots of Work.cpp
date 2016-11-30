// ==================================================
// Problem  :   Lots of Work
// Run time :   0.069 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 3;

int n, m, arr[MAXN];

bool check(int tm)
{
    int dayCnt = 0, i = 0;

    while(i < n && dayCnt <= m) {
        int curr = 0;

        while(i < n && curr+arr[i] <= tm) {
            curr += arr[i];
            ++i;
        }

        ++dayCnt;
    }

    return (dayCnt <= m);
}

int bin_search(int s, int t)
{
    int assumed_tm, ret;

    while(s <= t) {
        assumed_tm = (s + t) >> 1;

        if(check(assumed_tm)) {
            ret = assumed_tm;
            t = assumed_tm - 1;
        }
        else {
            s = assumed_tm + 1;
        }
    }

    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &m);

        int mx = 0, sum = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%d", arr+i);

            mx = max(mx, arr[i]);
            sum += arr[i];
        }

        printf("%d\n", bin_search(mx, sum));
    }

    return 0;
}
