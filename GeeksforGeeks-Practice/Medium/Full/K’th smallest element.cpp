// ==================================================
// Problem  :   K’th smallest element
// Run time :   0.073 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 3;

int arr[MAXN];

int partitioning(int left, int right)
{
    int pivot = arr[right], i = left - 1;

    for(int j = left; j < right; ++j)
        if(arr[j] <= pivot)
            swap(arr[++i], arr[j]);

    swap(arr[++i], arr[right]);

    return i;
}

int kth_smallest_element(int left, int right, int k)
{
    while(left <= right) {
        int pos = partitioning(left, right);

        if(pos == k)
            break;
        else if(pos < k)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return arr[k];
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", arr+i);

        scanf("%d", &k);

        printf("%d\n", kth_smallest_element(0, n-1, k-1));
    }

    return 0;
}
