// ==================================================
// Problem  :   338D - GCD Table
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <iostream>
using namespace std;

typedef     long long       LL;

LL get_gcd(LL m, LL n)
{
    while(n != 0) {
        LL t = m % n;
        m = n;
        n = t;
    }

    return m;
}

LL get_lcm(LL arr[], int k)
{
    LL lcm = 1;

    for(int i = 0; i < k; ++i)
        lcm = lcm / get_gcd(lcm, arr[i]) * arr[i];

    return lcm;
}

void extEuclid(LL a, LL b, LL &x, LL &y, LL &gcd)
{
    x = 0, y = 1, gcd = b;
    LL m, n, q, r;

    for(LL u = 1, v = 0; a != 0; gcd = a, a = r) {
        q = gcd / a; r = gcd % a;
        m = x-u*q; n = y-v*q;
        x = u; y = v; u = m; v = n;
    }
}

bool solve(LL n, LL m, int k, LL arr[])
{
    LL row = get_lcm(arr, k);

    if(row < 1 || n < row) return false;

    LL col, rem = 0;
    LL A = arr[0], r1 = rem;

    for(int i = 1; i < k; ++i) {
        LL B = arr[i], r2 = --rem;
        LL x, y, gcd, diff = r2 - r1;

        extEuclid(A, B, x, y, gcd);
        if(diff % gcd) return false;

        LL mod = B / gcd;
        x = x * diff / gcd;
        x = ((x % mod) + mod) % mod;

        col = A * x + r1;

        A = A * B / gcd;            // A * B / gcd = lcm of A, B.
        r1 = col;
    }

    if(col == 0) col = row;         // row = lcm of all ai.

    if(col < 1 || m-k+1 < col) return false;

    for(int i = 0; i < k; ++i)
        if(get_gcd(row, col+i) != arr[i])
            return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);

    LL n, m;
    int k;

    cin >> n >> m >> k;

    LL arr[k+3];

    for(int i = 0; i < k; ++i)
        cin >> arr[i];

    cout << (solve(n, m, k, arr)? "YES\n" : "NO\n");

    return 0;
}
