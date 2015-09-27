#include <cstdio>
#include <climits>
using namespace std;

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    long long arr[n+1];
    arr[0] = 0;

    for(int i = 1; i <= n; ++i) {
        scanf("%lld", arr+i);
        arr[i] += arr[i-1];
    }

    // modifying Kadane's algorithm.

    int start = 1, maxValue, ans = INT_MIN;

    for(int end = 1; end <= n; ++end) {
        maxValue = arr[end] - arr[start-1];

        if(maxValue > ans && maxValue <= m) ans = maxValue;

        if(maxValue > m) {
            ++start;
            if(start <= end) --end;
        }
    }

    printf("%d\n", ans);

    return 0;
}
