// ==================================================
// Problem  :   727C - Guess the Array
// Run time :   0.031 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

inline int ask(int i, int j)
{
    printf("? %d %d\n", i, j);
    fflush(stdout);

    int res;
    scanf("%d", &res);

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n+3];

    int a = ask(1, 2);
    int b = ask(1, 3);
    int c = ask(2, 3);

    arr[1] = (a + b - c) / 2;
    arr[2] = a - arr[1];
    arr[3] = b - arr[1];

    for(int i = 4; i <= n; ++i)
        arr[i] = ask(i-1, i) - arr[i-1];

    putchar('!');

    for(int i = 1; i <= n; ++i)
        printf(" %d", arr[i]);

    putchar('\n');

    return 0;
}
