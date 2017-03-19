// ==================================================
// Problem  :   1306 - Solutions to an Equation
// Runtime  :   0.024 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef     long long       LL;

void extEuclid(LL a, LL b, LL &x, LL &y, LL &gcd)
{
    x = 0; y = 1; gcd = b;
    LL m, n, q, r;

    for (LL u = 1, v = 0; a != 0; gcd = a, a = r) {
        q = gcd / a; r = gcd % a;
        m = x-u*q; n = y-v*q;
        x = u; y = v; u = m; v = n;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL a, b, c, x1, x2, y1, y2;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &x1, &x2, &y1, &y2);

        LL ans;

        if(!a and !b) {
            ans = (c)? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
        }
        else if(!a) {
            if(c % b) ans = 0;
            else {
                LL y = -c / b;
                ans = (y1 <= y and y <= y2)? (x2 - x1 + 1) : 0;
            }
        }
        else if(!b) {
            if(c % a) ans = 0;
            else {
                LL x = -c / a;
                ans = (x1 <= x and x <= x2)? (y2 - y1 + 1) : 0;
            }
        }
        else {
            LL x, y, g;
            extEuclid(a, b, x, y, g);

            if(c % g) ans = 0;
            else {
                x *= -c / g, y *= -c / g;

                double tx = (x1 - x) * g * 1.0 / b;
                double txx = (x2 - x) * g * 1.0 / b;
                if(tx > txx) swap(tx, txx);
                tx = ceil(tx);
                txx = floor(txx);

                double ty = (y - y1) * g * 1.0 / a;
                double tyy = (y - y2) * g * 1.0 / a;
                if(ty > tyy) swap(ty, tyy);
                ty = ceil(ty);
                tyy = floor(tyy);

                LL t1 = max(tx, ty), t2 = min(txx, tyy);

                ans = max(0LL, t2 - t1 + 1);
            }
        }

        printf("Case %d: %lld\n", tc, ans);
    }

    return 0;
}


/*
Concept:

Let,
a*x + b*y = c                           [x, y can be found by Extended Euclidean algorithm]
a*x + a*b*t/g - a*b*t/g + b*y = c       [ g = gcd(a, b) ]
a*(x + b*t/g) + b*(y - a*t/g) = c

So,
X = x + b*t/g
Y = y - a*t/g

Now,
x1 <= X <= x2
x1 <= x + b*t/g <= x2
(x1-x)*g/b <= t <= (x2-x)*g/b

y1 <= Y <= y2
y1 <= y - a*t/g <= y2
(y-y1)*g/a <= t <= (y-y2)*g/a

Combining these two, we get,
max( (x1-x)*g/b , (y-y1)*g/a ) <= t <= min( (x2-x)*g/b , (y-y2)*g/a )
*/
