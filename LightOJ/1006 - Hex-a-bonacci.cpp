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
