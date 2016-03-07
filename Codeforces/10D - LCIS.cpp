#include <bits/stdc++.h>
using namespace std;

typedef     pair<int, int>    ii;

const int MAXN = 500+3;

int n, m, arr1[MAXN], arr2[MAXN];

void LCIS()
{
    vector<ii> possible[m];
    int cnt[MAXN] = {0};
    int ans = 0, idx_j, idx_i;

    for(int i = 0; i < n; ++i) {
        int mx = 0;     // max value in candidate matrix.

        for(int j = 0; j < m; ++j) {
            if(arr1[i] == arr2[j]) {
                possible[j].push_back(ii(mx+1, i));
                cnt[j] = max(cnt[j], mx+1);

                if(cnt[j] > ans)
                    ans = cnt[j], idx_i = i, idx_j = j;
            }
            else if(arr1[i] > arr2[j])
                mx = max(mx, cnt[j]);
        }
    }

    printf("%d\n", ans);

    if(ans) {
        vector<int> sol;
        sol.push_back(arr2[idx_j]);
        --ans;

        for(int j = idx_j-1; j >= 0 && ans; --j) {
            if(arr2[j] < sol.back()) {
                for(auto& pr : possible[j]) {
                    if(pr.first == ans && pr.second < idx_i) {
                        sol.push_back(arr2[j]);
                        --ans;
                        idx_i = pr.second;
                        break;
                    }
                }
            }
        }

        printf("%d", sol.back());
        for(auto it = sol.rbegin()+1; it != sol.rend(); ++it)
            printf(" %d", *it);
        putchar('\n');
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "r", stdout);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", arr1+i);

    scanf("%d", &m);
    for(int i = 0; i < m; ++i) scanf("%d", arr2+i);

    LCIS();

    return 0;
}


// -------------------- Alternatively --------------------
/*
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 500+3;

struct iii {
    int val, row, col;

    iii(int v, int r, int c) { val = v, row = r, col = c; }
    bool operator<(const iii& a) const { return (val < a.val); };
};

int n, m, sz;
unordered_map<int, vector<int> > mp;
vector<iii> V;
vector<int> dp, dir;

int LIS(int u)
{
    if(dp[u] != -1) return dp[u];

    int mx = 0;

    for(int v = u+1; v < sz; ++v)
        if(V[u].val < V[v].val && V[u].row < V[v].row && V[u].col < V[v].col)
            if(mx < LIS(v)) {
                mx = LIS(v);
                dir[u] = v;
            }

    return dp[u] = 1 + mx;
}

int main()
{
    //freopen("in", "r", stdin);

    scanf("%d", &n);

    int val;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &val);
        mp[val].push_back(i);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; ++i) {
        scanf("%d", &val);

        if(mp.find(val) != mp.end())
            for(auto& col : mp[val])
                V.push_back(iii(val, i, col));
    }

    sort(V.begin(), V.end());

    sz = V.size();

    dp.assign(sz, -1);
    dir.assign(sz, -1);

    int ans = 0, start;

    for(int i = 0; i < sz; ++i)
        if(ans < LIS(i))
            ans = LIS(i), start = i;

    printf("%d\n", ans);

    if(ans) {
        printf("%d", V[start].val);
        start = dir[start];

        while(start != -1) {
            printf(" %d", V[start].val);
            start = dir[start];
        }

        putchar('\n');
    }

    return 0;
}

*/
