#include <cstdio>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

#define     ff          first
#define     ss          second

typedef     long long               LL;
typedef     pair<int,int>           ii;

const int MAXN = 10+3;

ii input[MAXN];

LL memo[MAXN][MAXN];
string memoSeq[MAXN][MAXN];

LL fn(int s, int t)
{
    if(s == t) {
        memo[s][s] = 0;

        string &str = memoSeq[s][s];
        str = 'A';

        if(s < 9) str.push_back(s+1+'0');
        else str += "10";                 // N will be no larger than 10.

        return 0;
    }

    LL &ret = memo[s][t];
    if(ret != -1) return ret;

    ret = LLONG_MAX;

    int mid;

    for(int i = s; i < t; ++i) {
        LL r = fn(s, i) + fn(i+1, t) + input[s].ff * input[t].ss * input[i].ss;

        if(ret > r) ret = r, mid = i;
    }

    string &str = memoSeq[s][t];

    if(s == mid) str = memoSeq[s][mid];
    else str = "(" + memoSeq[s][mid] + ")";

    str += " x ";

    if(mid+1 == t) str += memoSeq[mid+1][t];
    else str += "(" + memoSeq[mid+1][t] + ")";

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, tc = 0;

    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; ++i)
            scanf("%d %d", &input[i].ff, &input[i].ss);

        if(n == 1) {
            printf("Case %d: A1\n", ++tc);
            continue;
        }

        fill(&memo[0][0], &memo[MAXN][0], -1);

        fn(0, n-1);

        printf("Case %d: (%s)\n", ++tc, memoSeq[0][n-1].c_str());
    }

    return 0;
}
