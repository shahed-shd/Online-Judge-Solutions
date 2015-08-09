#include <cstdio>
using namespace std;

long long int arr[21] = {1};

long long int fac(long long int n)
{
    if(n == 0) return 1;

    if(arr[n])
        return arr[n];
    else {
        arr[n] = n * fac(n-1);
        return arr[n];
    }
}

int main()
{
    int t, tc, i, ans[21], index;
    long long int n;

    fac(20);    //filling up the array.

    scanf("%d", &t);
    tc = 0;

    while(t--) {
        scanf("%lld", &n);

        index = 0;
        for(i = 20; i >= 0 && n; i--) {
            if(n >= arr[i]) {
                n -= arr[i];
                ans[index++] = i;
            }
        }

        printf("Case %d: ", ++tc);

        if(n)
            printf("impossible\n");
        else {
            for(i = index - 1; i > 0; i--) {
                printf("%d!+", ans[i]);
            }
            printf("%d!\n", ans[i]);
        }
    }

    return 0;
}
