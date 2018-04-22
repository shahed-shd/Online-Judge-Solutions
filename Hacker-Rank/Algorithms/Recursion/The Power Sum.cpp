// ==================================================
// Problem  :   The Power Sum
// Score    :   20 /20
// Language :   C++14
// ==================================================


#include <cstdio>
#include <cmath>
using namespace std;


int ways(int currX, int n, int i)
{
    if(currX == 0) return 1;

    int r = pow(i, n);
    int cnt = 0;

    if(r <= currX) {
        cnt = ways(currX-r, n, i+1) + ways(currX, n, i+1);
    }

    return cnt;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int x, n;
    scanf("%d %d", &x, &n);

    printf("%d\n", ways(x, n, 1));

    return 0;
}
