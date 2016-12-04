// ==================================================
// Problem  :   Combination Sum
// Run time :   0.080 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAXN = 12 + 3;
const int MAXB = 30 + 3;
const int MAXX = 9 + 3;

int n, arr[MAXN], b;
int combination[MAXB], combIdx;
bool isEmpty;

void backtrack(int idx, int sum)
{
    bitset<MAXX> isTaken;

    for(int i = idx; i < n; ++i) {
        if(isTaken[arr[i]]) continue;
        isTaken[arr[i]] = true;

        if(sum + arr[i] == b) {
            isEmpty = false;

            putchar('(');
            for(int j = 0; j <= combIdx; ++j)
                printf("%d ", combination[j]);
            printf("%d)", arr[i]);
        }
        else if(sum + arr[i] < b) {
            combination[++combIdx] = arr[i];
            backtrack(i, sum+arr[i]);
            --combIdx;
        }
        else break;
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

        scanf("%d", &b);

        isEmpty = true;
        combIdx = -1;

        backtrack(0, 0);

        if(!isEmpty) putchar('\n');
        else puts("Empty");
    }

    return 0;
}
