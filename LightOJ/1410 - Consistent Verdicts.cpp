// ==================================================
// Problem  :   1410 - Consistent Verdicts
// Run time :   2.160 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 700 + 3;

vector<int> V;

template<class T>
inline T fastIn()
{
    register T a = 0;
    register char c = 0;
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

    int x[MAXN], y[MAXN];

    for(int tc = 1; tc <= t; ++tc) {
        V.clear();

        int n = fastIn<int>();

        // It is enough to count how many different distances among the persons.

        for(int i = 0; i < n; ++i) {
            x[i] = fastIn<int>();
            y[i] = fastIn<int>();

            for(int j = 0; j < i; ++j) {
                int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                V.push_back(dist);
            }
        }

        sort(V.begin(), V.end());

        printf("Case %d: %d\n", tc, 1 + distance(V.begin(), unique(V.begin(), V.end())));
    }

    return 0;
}
