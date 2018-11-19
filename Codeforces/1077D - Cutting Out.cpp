// ==================================================
// Problem  :   1077D - Cutting Out
// Run time :   0.093 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
using namespace std;


typedef     pair<int,int>       ii;


const int MAXN = 2e5 + 3;

int n, k;
int frequency[MAXN] = {0};
vector<ii> freq_num;
vector<int> ans;


bool check(int x)
{
    int curr_k = 0;
    for(auto &pr : freq_num) {
        int tmp = pr.first / x;
        if(tmp == 0) break;
        curr_k += tmp;
        if(curr_k >= k) break;
    }

    return curr_k >= k;
}


int bin_search()
{
    int lo = 1, hi = n, mid, ret = -1;

    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        if(check(mid)) {
            lo = mid+1;
            ret = mid;
        }
        else {
            hi = mid-1;
        }
    }

    return ret;
}


void get_ans(int x)
{
    int curr_k = 0;
    for(auto &pr : freq_num) {
        int tmp = pr.first / x;
        curr_k += tmp;
        while(tmp--) {
            ans.push_back(pr.second);
        }

        if(curr_k >= k) break;
    }
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    scanf("%d %d", &n, &k);

    int s, mxs = 0;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &s);
        ++frequency[s];
        mxs = max(mxs, s);
    }

    for(int i = 1; i <= mxs; ++i) {
        if(frequency[i]) {
            freq_num.push_back(ii(frequency[i], i));
        }
    }

    sort(freq_num.begin(), freq_num.end(), greater<ii>());

    int x = bin_search();
    get_ans(x);

    for(int i = 0; i < k; ++i) {
        printf("%d ", ans[i]);
    }

    return 0;
}
