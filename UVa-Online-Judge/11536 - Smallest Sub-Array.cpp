#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000001+3, MAXM = 1001+3;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    int arr[MAXN];

    for(int tc = 1; tc <= t; ++tc) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        printf("Case %d: ", tc);

        if(1 <= k && k <= 3) {
            printf("%d\n", k);
            continue;
        }

        arr[0] = 1, arr[1] = 2, arr[2] = 3;

        for(int i = 3; i < n; ++i)
            arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % m + 1;

        int lo, hi, cnt = 0, counter[MAXM] = {0};

        for(hi = 0; hi < n && cnt < k; ++hi) {
            int val = arr[hi];
            if(val && val <= k && !counter[val]) ++cnt;
            ++counter[val];
        }

        if(cnt < k) {
            puts("sequence nai");
            continue;
        }

        lo = 0;

        while(arr[lo] == 0 || arr[lo] > k || counter[arr[lo]] > 1) {
            --counter[arr[lo]];
            ++lo;
        }

        int len = hi-lo;

        for( ; hi < n; ++hi) {
            ++counter[arr[hi]];

            while(arr[lo] == 0 || arr[lo] > k || counter[arr[lo]] > 1) {
                --counter[arr[lo]];
                ++lo;
            }

            len = min(len, hi-lo+1);
        }

        printf("%d\n", len);
    }

    return 0;
}
