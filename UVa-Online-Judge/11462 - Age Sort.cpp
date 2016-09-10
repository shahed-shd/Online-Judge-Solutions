// ==================================================
// Problem  :   11462 - Age Sort
// Run time :   0.200 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 2000000 + 3;
short arr[MAXN];

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
    int n;

    while(n = fastIn<int>(), n) {
        for(int i = 0; i < n; ++i)
            arr[i] = fastIn<short>();

        sort(arr, arr+n);

        printf("%d", arr[0]);
        for(int i = 1; i < n; ++i)
            printf(" %d", arr[i]);

        putchar('\n');
    }

    return 0;
}
