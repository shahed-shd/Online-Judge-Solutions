// ==================================================
// Problem  :   1538C - Number of Pairs
// Run time :   0.078 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


typedef     long long       LL;


const int MAXN = 2e5 + 3;

int a[MAXN];


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);

        for(int i = 0; i < n; ++i) scanf("%d", a+i);

        sort(a, a+n);
        LL ans = 0;

        for(int i = 0; i < n; ++i) {
            int* lb = lower_bound(a+i+1, a+n, l - a[i]);
            int* ub = upper_bound(a+i+1, a+n, r - a[i]);
            ans += ub - lb;
        }

        printf("%lld\n", ans);
    }
    

    return 0;
}


// Alternative solution, two pointers algorithm

// ==================================================
// Problem  :   1538C - Number of Pairs
// Run time :   0.078 sec
// Language :   C++17
// ==================================================

/*
#include <cstdio>
#include <algorithm>
using namespace std;


typedef     long long       LL;


const int MAXN = 2e5 + 3;

int a[MAXN];


LL countPairs(int n, int x)
{
    int i = 0, j = n - 1;
    LL cnt = 0;

    while(i < n) {
        while(i < j && x <= a[i] + a[j]) {
            --j;
        }
        cnt += n - 1 - max(i, j);
        ++i;
    }

    return cnt;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);

        for(int i = 0; i < n; ++i) scanf("%d", a+i);

        sort(a, a+n);
        LL ans = countPairs(n, l) - countPairs(n, r+1);

        printf("%lld\n", ans);
    }
    

    return 0;
}
*/
