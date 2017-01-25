// ==================================================
// Problem  :   1425 - The Monkey and the Oiled Bamboo
// Run time :   0.192 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;

int rungs[MAXN];

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

        rungs[0] = 0;
        for(int i = 1; i <= n; ++i) rungs[i] = fastIn<int>();

        int ans = 0, curr;

        for(int i = n-1; i >= 0; --i) {
            curr = rungs[i+1] - rungs[i];

            if(curr == ans) ++curr;

            ans = max(ans, curr);
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
