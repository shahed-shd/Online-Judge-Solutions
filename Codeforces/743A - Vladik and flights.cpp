// ==================================================
// Problem  :   743A - Vladik and flights
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    char str[MAXN];
    scanf("%s", str);

    --a, --b;

    puts(str[a] == str[b]? "0" : "1");

    return 0;
}
