// ==================================================
// Problem  :   1374 - Confusion in the Problemset
// Run time :   0.128 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

const int MAXR = 1e6 + 3;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = (c - '0');

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        int freq[MAXR] = {0};

        for(int i = 1; i <= n; ++i)
            ++freq[fastIn<int>()];

        bool ans = true;
        int upto = (n&1)? (n-1)/2 : n/2;

        if((n & 1) && freq[(n-1)/2] != 1)
            ans = false;

        for(int i = 0; i < upto && ans; ++i)
            if(freq[i] + freq[n-1-i] != 2)
                ans = false;

        printf("Case %d: %s\n", tc, (ans? "yes" : "no"));
    }

    return 0;
}
