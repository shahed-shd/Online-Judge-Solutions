// ==================================================
// Problem   :   545C - Woodcutters
// Run time  :   0.046 sec.
// Language  :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 3;

int n, x[MAXN], h[MAXN];
int memo[MAXN][3];

int fn(int idx, int dir)
{
    if(idx >= n) return 0;

    int &rf = memo[idx][dir];
    if(rf != -1) return rf;

    int occupiedUpto = (dir <= 1)? x[idx] : x[idx]+h[idx];

    rf = fn(idx+1, 0);
    if(occupiedUpto < x[idx+1] - h[idx+1])
        rf = max(rf, 1 + fn(idx+1, 1));
    if(idx+2 < n and x[idx+1]+h[idx+1] < x[idx+2])
        rf = max(rf, 1 + fn(idx+1, 2));
    if(idx+2 >= n)
        rf = max(rf, 1+fn(idx+1, 2));

    return rf;
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) scanf("%d %d", x+i, h+i);

    for(int i = 0; i < n; ++i) memo[i][0] = memo[i][1] = memo[i][2] = -1;

    printf("%d\n", max(fn(0, 0), max(fn(0, 1), fn(0, 2))));

    return 0;
}
