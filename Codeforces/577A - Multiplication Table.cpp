// ==================================================
// Problem  :   577A - Multiplication Table
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef     long long       LL;

int main()
{
    //freopen("in.txt", "r", stdin);

    int n, x;
    scanf("%d %d", &n, &x);

    int upto = min(n, int(sqrt(x))), cnt = 0;

    for(int i = 1; i <= upto; ++i)
        if(x % i == 0 && x/i <= n)
            cnt += 2;

    if(upto * upto == x && x <= LL(n)*n) --cnt;

    printf("%d\n", cnt);

    return 0;
}
