#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXR = 10, MAXC = 100;

int m, n, mat[MAXR][MAXC], dp[MAXR][MAXC];

int fn(int row, int col)
{
    if(col == n) return 0;

    if(row == -1) row = m-1;
    else if(row == m) row = 0;

    int& ret = dp[row][col];
    if(ret != INT_MAX) return ret;

    return ret = mat[row][col] + min(fn(row-1, col+1), min(fn(row, col+1), fn(row+1, col+1)));
}

void printSolution(int row, int col)
{
    if(col == n) return;

    if(row == -1) row = m-1;
    else if(row == m) row = 0;

    printf("%d", row+1);
    if(col < n-1) putchar(' ');

    int mn = INT_MAX, rowNext;

    if(row == 0) {
        if(fn(row, col+1) < mn)
            mn = fn(row, col+1), rowNext = row;
        if(fn(row+1, col+1) < mn)
            mn = fn(row+1, col+1), rowNext = row+1;
        if(fn(row-1, col+1) < mn)
            mn = fn(row-1, col+1), rowNext = row-1;
    }
    else if(row == m-1) {
        if(fn(row+1, col+1) < mn)
            mn = fn(row+1, col+1), rowNext = row+1;
        if(fn(row-1, col+1) < mn)
            mn = fn(row-1, col+1), rowNext = row-1;
        if(fn(row, col+1) < mn)
            mn = fn(row, col+1), rowNext = row;
    }
    else {
        if(fn(row-1, col+1) < mn)
            mn = fn(row-1, col+1), rowNext = row-1;
        if(fn(row, col+1) < mn)
            mn = fn(row, col+1), rowNext = row;
        if(fn(row+1, col+1) < mn)
            mn = fn(row+1, col+1), rowNext = row+1;
    }

    printSolution(rowNext, col+1);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    while(scanf("%d %d", &m, &n) != EOF) {
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &mat[i][j]), dp[i][j] = INT_MAX;

        int mn = INT_MAX, startRow;

        for(int i = 0; i < m; ++i)
            if(fn(i, 0) < mn)
                mn = fn(i, 0), startRow = i;

        printSolution(startRow, 0);

        printf("\n%d\n", mn);
    }

    return 0;
}
