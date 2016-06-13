#include <cstdio>
using namespace std;

int zeros(int num)  // Finds how many trailing zeroes in factorial(num).
{
    int cnt = 0;

    while(num >= 5)
        num /= 5, cnt += num;

    return cnt;
}

int bin_search(int s, int t, int q)
{
    while(s <= t) {
        int mid = (s+t) >> 1;

        int z = zeros(mid);

        if(q == z) return mid;
        else if(q > z) s = mid+1;
        else t = mid-1;
    }

    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int q;
        scanf("%d", &q);

        printf("Case %d: ", tc);

        int n = bin_search(5, q*5, q);

        (n != -1)? printf("%d\n", n - (n%5)) : puts("impossible");
    }

    return 0;
}
