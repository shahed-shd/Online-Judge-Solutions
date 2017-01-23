// ==================================================
// Problem  :   760B - Frodo and pillows
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

typedef     long long       LL;

LL n, m, k;

LL minPillowForSide(LL bed, LL x)
{
    LL ret = (x - 1) * x / 2;

    if(bed > x-1) {
        ret += bed - (x-1);
    }
    else if(bed < x-1) {
        LL tmp = x-1 - bed;
        ret -= tmp * (tmp+1)/2;
    }

    return ret;
}

bool check(LL x)
{
    return (minPillowForSide(k-1, x) + x + minPillowForSide(n-k, x) <= m);
}

LL binSearch(LL s, LL t)
{
    LL ret;

    while(s <= t) {
        LL mid = (s + t) >> 1;

        if(check(mid)) {
            ret = mid;
            s = mid + 1;
        }
        else {
            t = mid - 1;
        }
    }

    return ret;
}

int main()
{
    scanf("%I64d %I64d %I64d", &n, &m, &k);

    printf("%I64d\n", binSearch(1, m));

    return 0;
}
