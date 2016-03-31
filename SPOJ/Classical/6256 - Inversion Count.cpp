#include <cstdio>
using namespace std;

typedef     long long   LL;

const int MAXN = 200000+3;

int arr[MAXN], temp[MAXN];

LL mergeSort(int left, int right)
{
    if(left == right) return 0L;

    int mid = (left + right) / 2;

    LL invCnt = mergeSort(left, mid) + mergeSort(mid+1, right);

    int i = left, j = mid+1;

    for(int k = left; k <= right; ++k) {
        if(i <= mid && (arr[i] < arr[j] || j > right))
            temp[k] = arr[i++];
        else {
            temp[k] = arr[j++];

            if(i <= mid) invCnt += mid - i + 1;	// This is tricky.
        }
    }

    for(int k = left; k <= right; ++k)
        arr[k] = temp[k];

    return invCnt;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", arr+i);

        printf("%lld\n", mergeSort(0, n-1));
    }

    return 0;
}
