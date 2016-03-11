#include <cstdio>
#include <bitset>
#include <climits>
using namespace std;

typedef     pair<int,int>   ii;

const int MAXN = 100+3;

int  n, arr[MAXN];

bitset<MAXN> isCalculated[MAXN];
ii dp[MAXN][MAXN];

ii fn(int s, int t)
{
    if(s == t) return ii(arr[s] % 100, 0);

    if(isCalculated[s][t]) return dp[s][t];

    int mn = INT_MAX, sum;

    for(int mid = s; mid < t; ++mid) {
        ii left = fn(s, mid);
        ii right = fn(mid+1, t);

        int smoke = left.second + right.second + left.first * right.first;
        if(mn > smoke) {
            mn = smoke;
            sum = (left.first + right.first) % 100;
        }
    }

    isCalculated[s][t] = true;
    return dp[s][t] = ii(sum, mn);
}

int main()
{
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++i)
            scanf("%d", arr+i);

        for(int i = 0; i < MAXN; ++i)
            isCalculated[i].reset();

        printf("%d\n", fn(0, n-1).second);
    }

    return 0;
}
