#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10000+3;

int main()
{
    //freopen("in", "r", stdin);

    int arr[MAXN], n = 0;

    while(scanf("%d", arr+(n++)) != EOF) {
        nth_element(arr, arr+(n>>1), arr+n);    // (n>>1) is equivalent to (n/2).
        int median = arr[n>>1];

        if(!(n & 1)) {
            nth_element(arr, arr+(n>>1)-1, arr+n);
            median = (median + arr[(n>>1)-1]) >> 1;
        }

        printf("%d\n", median);
    }


    return 0;
}
