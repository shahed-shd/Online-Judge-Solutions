// ==================================================
// Problem  :   1004B - Sonya and Exhibition
// Run time :   0.031 sec
// Language :   C++14
// ==================================================


#include <cstdio>
using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    while(m--)
        scanf("%*d %*d");

    for(int i = 0; i < n; ++i)
        putchar((i & 1)? '0' : '1');

    putchar('\n');

    return 0;
}
