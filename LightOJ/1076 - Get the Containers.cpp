// ==================================================
// Problem  :   1076 - Get the Containers
// Run time :   0.008 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 1000+3;

int vessels[MAXN];
int n, m;

template<class T>
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

bool check(int cap)
{
    int v = 0;
    int containerRemain = m;

    while(v < n && containerRemain) {
        int pour = 0;

        while(v < n && pour + vessels[v] <= cap) {
            if(n - v <= containerRemain)
                return true;
            pour += vessels[v++];
        }

        --containerRemain;
    }

    return (v == n);
}

int binSearch(int s, int t)
{
    int ret;

    while(s <= t) {
        int mid = (s + t) >> 1;

        if(check(mid)) {
            ret = mid;
            t = mid - 1;
        }
        else s = mid + 1;
    }

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        n = fastIn<int>(), m = fastIn<int>();

        int mx = -1, sum = 0;

        for(int i = 0; i < n; ++i) {
            vessels[i] = fastIn<int>();
            sum += vessels[i];
            if(vessels[i] > mx) mx = vessels[i];
        }

        printf("Case %d: %d\n", tc, binSearch(mx, sum));
    }

    return 0;
}
