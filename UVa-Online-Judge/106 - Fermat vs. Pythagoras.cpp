#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

const int MAXN = 1e6 + 3;

int premitiveCount[MAXN] = {0}, p[MAXN] = {0};

int gcd(int m, int n)
{
    int t;

    while (n != 0) {
        t = m % n;
        m = n;
        n = t;
	}

    return m;
}

void preprocess()
{
    int a, b, c, upto = round(sqrt(MAXN * 1.0));
    int pRange[MAXN];

    fill_n(pRange, MAXN, INT_MAX);

    for(int m = 1; m <= upto; ++m) {
        for(int n = 1; n < m; ++n) {
            if((m-n) & 1 && gcd(m, n) == 1) {
                a = m*m - n*n;
                b = 2 * m * n;
                c = m*m + n*n;

                if(c < MAXN) {
                    ++premitiveCount[c];

                    for(int k = 1; k*c < MAXN; ++k) {
                        int tmp = k*c;
                        pRange[k*a] = min(pRange[k*a], tmp);
                        pRange[k*b] = min(pRange[k*b], tmp);
                        pRange[tmp] = min(pRange[tmp], tmp);
                    }
                }
                else break;
            }
        }
    }

    for(int i = 1; i < MAXN; ++i)
        if(pRange[i] != INT_MAX)
            ++p[pRange[i]];

    for(int i = 1; i < MAXN; ++i) {
        premitiveCount[i] += premitiveCount[i-1];
        p[i] += p[i-1];
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;

    preprocess();

    while(scanf("%d", &n) != EOF)
        printf("%d %d\n", premitiveCount[n], n - p[n]);

    return 0;
}
