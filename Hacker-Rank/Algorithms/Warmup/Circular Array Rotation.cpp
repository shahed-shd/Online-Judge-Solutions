#include <cstdio>
using namespace std;

int main()
{
    int n, k, q;

    scanf("%d %d %d", &n, &k, &q);

    int arr[n+3];

    for(int i = 0; i < n; ++i) scanf("%d", arr+i);

    k %= n;
    int m;

    while(q--) {
        scanf("%d", &m);
        printf("%d\n", arr[(m-k+n) % n]);
    }

    return 0;
}

