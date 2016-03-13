#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXK = 30+3;

typedef     pair<vector<int>, int>  vi;

int k, n;
vector<vi> seq;

int dp[MAXK], dir[MAXK];

bool isInnermost(const vi &a, const vi &b)  // returns true if a can be nested in b.
{                                           // otherwise, returns false.
    for(int i = 0; i < n; ++i)
        if(a.first[i] >= b.first[i]) return false;

    return true;
}

int LIS(int u)
{
    if(dp[u] != -1) return dp[u];

    int mx = 0;

    for(int v = u+1; v < k; ++v)
        if(isInnermost(seq[u], seq[v]) && mx < LIS(v))
                mx = LIS(v), dir[u] = v;

    return dp[u] = 1 + mx;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    while(scanf("%d %d", &k, &n) != EOF) {
        seq.clear();

        for(int i = 0; i < k; ++i) {
            int tmp;
            vector<int> box;

            for(int j = 0; j < n; ++j) {
                scanf("%d", &tmp);
                box.push_back(tmp);
            }

            sort(box.begin(), box.end());

            seq.push_back(vi(box, i+1));
        }

        sort(seq.begin(), seq.end());

        fill_n(dp, MAXK, -1);
        fill_n(dir, MAXK, -1);

        int mxLen = 0, start;

        for(int i = 0; i < k; ++i)
            if(mxLen < LIS(i))
                mxLen = LIS(i), start = i;

        printf("%d\n", mxLen);

        printf("%d", seq[start].second);
        start = dir[start];

        while(start != -1) {
            printf(" %d", seq[start].second);
            start = dir[start];
        }
        putchar('\n');
    }

    return 0;
}
