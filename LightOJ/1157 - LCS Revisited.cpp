#include <iostream>
using namespace std;

const int MAXL = 1000+3, MOD = 1000007;

string str_a, str_b;
int len_a, len_b;

int dp[MAXL][MAXL], next_a[MAXL][26], next_b[MAXL][26], memo[MAXL][MAXL];

int LCS(int idx1, int idx2)
{
    if(idx1 == len_a || idx2 == len_b) return 0;

    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

    if(str_a[idx1] == str_b[idx2])
        return dp[idx1][idx2] = 1 + LCS(idx1+1, idx2+1);
    else
        return dp[idx1][idx2] = max(LCS(idx1+1, idx2), LCS(idx1, idx2+1));
}

int cnt(int idx1, int idx2)
{
    if(idx1 == len_a || idx2 == len_b) return 1;

    if(memo[idx1][idx2] != -1) return memo[idx1][idx2];

    int len_lcs = LCS(idx1, idx2);

    if(len_lcs == 0) return memo[idx1][idx2] = 1;

    int ret = 0;

    for(int i = 0; i < 26; ++i) {
        int x = next_a[idx1][i];
        int y = next_b[idx2][i];

        if(LCS(x, y) == len_lcs) {
            ret += cnt(x+1, y+1);
            ret %= MOD;
        }
    }

    return memo[idx1][idx2] = ret;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        cin >> str_a >> str_b;
        len_a = str_a.length(), len_b = str_b.length();

        int last[26];

        for(int i = 0; i < 26; ++i)
            last[i] = len_a;

        for(int i = len_a-1; i >= 0; --i) {
            last[str_a[i] - 'a'] = i;

            for(int j = 0; j < 26; ++j)
                next_a[i][j] = last[j];
        }

        for(int i = 0; i < 26; ++i)
            last[i] = len_b;

        for(int i = len_b-1; i >= 0; --i) {
            last[str_b[i] - 'a'] = i;

            for(int j = 0; j < 26; ++j)
                next_b[i][j] = last[j];
        }

        fill(&dp[0][0], &dp[MAXL][0], -1);
        fill(&memo[0][0], &memo[MAXL][0], -1);

        cout << "Case " << tc << ": " << cnt(0, 0) << '\n';
    }

    return 0;
}
