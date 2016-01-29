// Run time: 0.024 sec

#include <iostream>
#include<stdio.h>
using namespace std;

#define M 10000007

long long int a, b, c, d, e, f, *p;

int fn( long long int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;

    if(*(p+n) != -111111) return *(p+n);
    else {
        *(p+n) = ((fn(n-1) % M) + (fn(n-2) % M) + (fn(n-3) % M) + (fn(n-4) % M) + (fn(n-5) % M) + (fn(n-6) % M)) % 10000007 ;
	//here is the mathematical fact is, (A+B) % M = ((A%M) + (B%M)) % M.
        return *(p+n);
    }
}

int main() {
    long long int n, caseno = 0, cases;

    scanf("%lld", &cases);

    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);

        p = new long long int [n+1];

        for(int i = 6; i <= n; i++) *(p+i) = -111111;

        printf("Case %lld: %d\n", ++caseno, fn(n) % 10000007);

        delete [] p;
    }

    return 0;
}


// -------------------------------- Alternatively --------------------------------
// Run time: 0.012 sec
/*

#include <cstdio>
#include <vector>
using namespace std;

const int M = 10000007;

int a, b, c, d, e, f;
vector<int> dp;

int fn(int n) {
    if(dp[n] != -1) return dp[n];

    return dp[n] = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6)) % M;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        dp.clear();

        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);

        dp.assign(n+1, -1);

        dp[0] = a % M;
        dp[1] = b % M;
        dp[2] = c % M;
        dp[3] = d % M;
        dp[4] = e % M;
        dp[5] = f % M;

        printf("Case %d: %d\n", tc, fn(n));
    }

    return 0;
}

*/


// --------------------------- Alternatively (iterative, not recursive) ---------------------------
// Run time : 0.004 sec
/*
#include <cstdio>
using namespace std;

const int MAXN = 10000+5, M = 10000007;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int arr[MAXN], tmp;

        for(int i = 0; i < 6; ++i) {
            scanf("%d", &tmp);
            arr[i] = tmp % M;
        }

        int n;
        scanf("%d", &n);

        for(int i = 6; i <= n; ++i)
            arr[i] = (arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4] + arr[i-5] + arr[i-6]) % M;

        printf("Case %d: %d\n", tc, arr[n]);
    }

    return 0;
}

*/
