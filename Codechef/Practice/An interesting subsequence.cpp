#include <bits/stdc++.h>
using namespace std;

typedef     pair<int, int>    ii;

const int MAXN = 5000+3;

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
