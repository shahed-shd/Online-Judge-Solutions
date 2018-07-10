// ==================================================
// Problem  :   1004C - Sonya and Robots
// Run time :   0.061 sec
// Language :   C++14
// ==================================================


#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;


typedef     long long       LL;


const int MAXAI = 1e5 + 3;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<int> a(n);

    for(auto &x : a)
        scanf("%d", &x);

    vector<int> cum_unq_cnt(n);

    bitset<MAXAI> isCounted;

    for(int i = n-1; i >= 0; --i) {
        int val = a[i];

        if(!isCounted[val]) {
            isCounted[val] = true;
            cum_unq_cnt[i] = 1;
        }

        cum_unq_cnt[i] += (i == n-1)? 0 : cum_unq_cnt[i+1];
    }

    isCounted.reset();
    LL ans = 0;

    for(int i = 0; i < n-1; ++i) {
        int val = a[i];

        if(!isCounted[val]) {
            isCounted[val] = true;
            ans += cum_unq_cnt[i+1];
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
