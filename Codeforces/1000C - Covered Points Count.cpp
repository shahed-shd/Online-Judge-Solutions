// ==================================================
// Problem  :   1000C - Covered Points Count
// Run time :   0.374 sec
// Language :   C++14
// ==================================================


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


typedef     long long       LL;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<LL> vec_li, vec_ri, coords;
    LL a, b;

    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        vec_li.push_back(a);
        vec_ri.push_back(b);

        coords.push_back(a);
        coords.push_back(b+1);
    }

    // Keep only unique coordinates.
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    int coords_sz = coords.size();
    vector<int> vec_cnt(coords_sz, 0);

    for(int i = 0; i < n; ++i) {
        a = vec_li[i];
        b = vec_ri[i];

        int idx_a = lower_bound(coords.begin(), coords.end(), a) - coords.begin();
        int idx_b = lower_bound(coords.begin(), coords.end(), b+1) - coords.begin();

        ++vec_cnt[idx_a];
        --vec_cnt[idx_b];
    }

    vector<LL> vec_ans(n+1, 0);
    int curr_cnt = 0;

    for(int i = 0; i < coords_sz; ++i) {
        curr_cnt += vec_cnt[i];
        vec_ans[curr_cnt] += ((i+1 < coords_sz)? coords[i+1] - coords[i] : 1);
    }

    for(int i = 1; i <= n; ++i) {
        printf("%lld", vec_ans[i]);
        putchar(i == n? '\n' : ' ');
    }

    return 0;
}
