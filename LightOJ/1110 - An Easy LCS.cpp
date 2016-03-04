#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const short MAXL = 100+3;

char str_a[MAXL], str_b[MAXL];

short dp[MAXL][MAXL];
string str[MAXL][MAXL];

short LCS(short i1, short i2)
{
    if(str_a[i1] == '\0' || str_b[i2] == '\0') {
        str[i1][i2] = string();
        return 0;
    }

    short& ret = dp[i1][i2];

    if(ret != -1) return ret;

    if(str_a[i1] == str_b[i2]) {
        ret = 1 + LCS(i1+1, i2+1);
        str[i1][i2] = str_a[i1] + str[i1+1][i2+1];
    }
    else {
        short val1 = LCS(i1+1, i2), val2 = LCS(i1, i2+1);

        if(val1 > val2) {
            ret = val1;
            str[i1][i2] = str[i1+1][i2];
        }
        else if(val1 < val2) {
            ret = val2;
            str[i1][i2] = str[i1][i2+1];
        }
        else {  // LCS(i1+1, i2) == LCS(i1, i2+1)
            ret = val1;
            str[i1][i2] = min(str[i1+1][i2], str[i1][i2+1]);
        }
    }

    return ret;
}


int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%s %s", str_a, str_b);

        fill(&dp[0][0], &dp[MAXL][0], -1);

        if(LCS(0, 0))
            printf("Case %d: %s\n", tc, str[0][0].c_str());
        else
            printf("Case %d: :(\n", tc);
    }

    return 0;
}
