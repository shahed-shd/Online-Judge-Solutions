#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

const int MAXN = 1000+3;

#define     p(x)    ((x == -1)? 2 : x)

int n;
string init1, init2, ans;
int8_t dp[MAXN][MAXN][3];
bool isPossible;

bool fn(int16_t init1_idx, int16_t init2_idx, int8_t diff_res1_res2)
{
    if(isPossible) return false;    // No need to execute any more.
    if(init1_idx == n && init2_idx == n) { isPossible = true; return true; }

    if(dp[init1_idx][init2_idx][p(diff_res1_res2)] != -1)
        return dp[init1_idx][init2_idx][p(diff_res1_res2)];

    bool flag1 = false, flag2 = false, ret = false;

    if(diff_res1_res2 == -1) {
        if(init1_idx < n && init1[init1_idx] == '0') flag1 = fn(init1_idx+1, init2_idx, 0);
        if(isPossible) ans.push_back('1');

        if(init2_idx < n && init2[init2_idx] == '0') flag2 = fn(init1_idx, init2_idx+1, 0);
        if(!flag1 && isPossible) ans.push_back('2');

        ret = flag1 || flag2;
    }
    else if(diff_res1_res2 == 1) {
        if(init1_idx < n && init1[init1_idx] == '1') flag1 = fn(init1_idx+1, init2_idx, 0);
        if(isPossible) ans.push_back('1');

        if(init2_idx < n && init2[init2_idx] == '1') flag2 = fn(init1_idx, init2_idx+1, 0);
        if(!flag1 && isPossible) ans.push_back('2');

        ret = flag1 || flag2;
    }
    else if(diff_res1_res2 == 0) {
        if(init1_idx < n && init1[init1_idx] == '0') flag1 = fn(init1_idx+1, init2_idx, 1);
        if(isPossible) ans.push_back('1');

        if(init2_idx < n && init2[init2_idx] == '0') flag2 = fn(init1_idx, init2_idx+1, 1);
        if(!flag1 && isPossible) ans.push_back('2');

        ret = flag1 || flag2;

        if(init1_idx < n && init1[init1_idx] == '1') flag1 = fn(init1_idx+1, init2_idx, -1);
        if(!ret && isPossible) ans.push_back('1');

        if(init2_idx < n && init2[init2_idx] == '1') flag2 = fn(init1_idx, init2_idx+1, -1);
        if(!ret && !flag1 && isPossible) ans.push_back('2');

        ret = ret || flag1 || flag2;
    }

    dp[init1_idx][init2_idx][p(diff_res1_res2)] = ret;

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> n) {
        ans.clear();

        cin >> init1 >> init2;

        fill(&dp[0][0][0], &dp[MAXN][0][0], -1);
        isPossible = false;

        fn(0, 0, 0);

        if(isPossible) {
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
        }
        else cout << "Impossible\n";
    }

    return 0;
}
