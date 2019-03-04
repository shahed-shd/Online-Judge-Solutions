// ==================================================
// Problem  :   1114D - Flood Fill
// Run time :   0.155 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

struct Info {
    int start_idx, color_val, end_idx;
};

const int MAXN = 5000 + 3;
const int INF = INT_MAX;

int n;
vector<Info> info;
int memo[MAXN][MAXN];


int dp(int si, int ei)
{
    if(si == 1 and ei == n) {
        return 0;
    }

    int &ret = memo[si][ei];
    if(ret != -1) return ret;

    ret = INF;
    if(1 <= si-1 and ei+1 <= n and info[si-1].color_val == info[ei+1].color_val) {
        ret = min(ret, 1 + dp(info[si-1].start_idx, info[ei+1].end_idx));
    } else {
        if(1 <= si-1) {
            ret = min(ret, 1 + dp(info[si-1].start_idx, ei));
        }
        if(ei+1 <= n) {
            ret = min(ret, 1 + dp(si, info[ei+1].end_idx));
        }
    }

    return ret;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    scanf("%d", &n);

    int val;
    info.resize(n+3);
    info[0].color_val = 0;  // Assigning such a color which will not appear in input.

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        Info &prev = info[i-1];
        Info &curr = info[i];
        curr.color_val = val;
        curr.start_idx = (prev.color_val == val)? prev.start_idx : i;
    }

    info[n+1].color_val = 0;  // Assigning such a color which will not appear in input.
    for(int i = n; i >= 1; --i) {
        Info &nxt = info[i+1];
        Info &curr = info[i];
        curr.end_idx = (nxt.color_val == curr.color_val)? nxt.end_idx : i;
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            memo[i][j] = -1;

    int ans = INF;
    for(int i = 1; i <= n; ++i) {
        Info &curr = info[i];
        if(curr.color_val != info[i-1].color_val) {
            ans = min(ans, dp(curr.start_idx, curr.end_idx));
        }
    }

    printf("%d\n", ans);

    return 0;
}
