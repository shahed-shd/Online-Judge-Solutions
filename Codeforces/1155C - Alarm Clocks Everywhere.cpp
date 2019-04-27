// ==================================================
// Problem  :   1155C - Alarm Clocks Everywhere
// Run time :   0.280 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
using namespace std;


typedef     long long       LL;


LL calc_gcd(LL m, LL n)
{
    while (n != 0) {
        LL t = m % n;
        m = n;
        n = t;
    }

    return m;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    vector<LL> x_vec;
    LL temp;

    // Input x values
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        x_vec.push_back(temp);
    }

    // Calculate GCD of differences of consecutive x values.
    LL gcd = x_vec[1] - x_vec[0], diff;

    for(int i = 2; i < n; ++i) {
        diff = x_vec[i] - x_vec[i-1];
        gcd = calc_gcd(gcd, diff);
    }

    // Input p values and check if it is a divisor of the gcd value.
    LL p, y = x_vec[0];
    int j = -1;                 // -1 indicadtes that desired p value not found.

    for(int i = 1; i <= m ; ++i) {
        scanf("%lld", &p);
        if(j == -1) {           // If desired p value not found yet.
            if(gcd % p == 0) {
                j = i;          // Desired p value found, assign index of the p value.
            }
        }
    }

    if(j == -1) {
        printf("NO\n");
    }
    else {
        printf("YES\n%lld %d\n", y, j);
    }

    return 0;
}
