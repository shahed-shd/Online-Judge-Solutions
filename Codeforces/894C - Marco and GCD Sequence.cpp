// ==================================================
// Problem  :   894C - Marco and GCD Sequence
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

const int MAXM = 1000 + 3;

int main()
{
    //freopen("in.txt", "r", stdin);

    int m, s[MAXM];

    scanf("%d", &m);

    for(int i = 0; i < m; ++i) scanf("%d", s+i);

    for(int i = 1; i < m; ++i) {
        if(s[i] % s[0]) {
            puts("-1");
            return 0;
        }
    }

    printf("%d\n%d", 2*m-1, s[0]);

    for(int i = 1; i < m; ++i)
        printf(" %d %d", s[i], s[0]);

    putchar('\n');

    return 0;
}
