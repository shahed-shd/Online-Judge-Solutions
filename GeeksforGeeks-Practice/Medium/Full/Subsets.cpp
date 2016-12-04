// ==================================================
// Problem  :   Subsets
// Run time :   0.083 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAXN = 12 + 3;
const int MAXX = 9 + 3;

int n, arr[MAXN];
int combination[MAXN], combIdx;

void backtrack(int idx)
{
    bitset<MAXX> isTaken;

    for(int i = idx; i < n; ++i) {
        if(isTaken[arr[i]]) continue;
        isTaken[arr[i]] = true;

        putchar('(');
        for(int j = 0; j <= combIdx; ++j)
            printf("%d ", combination[j]);
        printf("%d)", arr[i]);

        combination[++combIdx] = arr[i];
        backtrack(i+1);
        --combIdx;
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", arr+i);
        sort(arr, arr+n);

        combIdx = -1;
        printf("()");
        backtrack(0);
        putchar('\n');
    }

    return 0;
}
