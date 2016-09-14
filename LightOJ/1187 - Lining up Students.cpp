// ==================================================
// Problem  :   1187 - Lining up Students
// Run time :   0.068 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

template <class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

int main()
{
    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        int a, ans = 1;
        fastIn<int>();  // Feed the first value.

        for(int i = 2; i <= n; ++i) {
            a = fastIn<int>();
            if(i - a <= ans) ++ans;
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
