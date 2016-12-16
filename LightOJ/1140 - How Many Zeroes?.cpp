// ==================================================
// Problem  :   1140 - How Many Zeroes?
// Run time :   0.020 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cmath>
using namespace std;

typedef     long long       LL;

LL memo[10][10] = {0};
LL subtract[10];

void preprocess()
{
    for(int i = 0; i <= 9; ++i)
        memo[i][9] = 1;

    for(int i = 8; i >= 0; --i) {
        memo[0][i] = memo[9][i+1] + int(pow(10, 9-i));

        for(int j = 1; j <= 9; ++j) {
            memo[j][i] = memo[9][i+1];
            memo[j][i] += memo[j-1][i];
        }
    }

    LL a = 1;
    for(int i = 8; i >= 0; --i) {
        a *= 10;
        subtract[i] = a;
        subtract[i] += subtract[i+1];
    }
}

LL upto(LL n)
{
    char str[15];
    int len = sprintf(str, "%lld", n);

    LL res = 0, sIdx = 0;

    for(int i = 9-len+1; i <= 9; ++i, ++sIdx) {
        int d = str[sIdx] - '0';

        if(d) {
            res += memo[d-1][i] - ((sIdx == 0)? subtract[i] : 0);
        }
        else {
            if(sIdx < len-1) {
                LL tmp;
                sscanf(&str[sIdx+1], "%lld", &tmp);
                res += tmp;
            }
        }
    }

    for(int i = 0; i < len; ++i)
        if(str[i] == '0') ++res;

    return res;
}

int main()
{
    preprocess();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL a, b;
        scanf("%lld %lld", &a, &b);

        LL x = ((a)? upto(a-1) : 0);
        LL y = upto(b);

        printf("Case %d: %lld\n", tc, y-x);
    }

    return 0;
}
