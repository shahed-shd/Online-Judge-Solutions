#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 1e6 + 3;

double log10_of_fact_of[MAXN];

template<class T>
inline T fastIn()
{
    register char ch = 0;
    register T a = 0;
    bool neg = false;

    while(ch < 33) ch = getchar();

    if(ch == '-') neg = true;
    else a = ch - '0';

    while(ch = getchar(), ch > 33)
        a = a * 10 + (ch - '0');

    return (neg? -a : a);
}

int main()
{
    log10_of_fact_of[0] = 0;

    for(int i = 1; i < MAXN; ++i)
        log10_of_fact_of[i] = log10(i) + log10_of_fact_of[i-1];

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>(), base = fastIn<int>();

        int ans = int(log10_of_fact_of[n] / (log10_of_fact_of[base]-log10_of_fact_of[base-1])) + 1;

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
