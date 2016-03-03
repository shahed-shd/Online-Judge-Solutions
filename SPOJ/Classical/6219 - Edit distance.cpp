#include <iostream>
#include <cmath>
using namespace std;

const int MAXL = 2000;

string a, b;
int len_a, len_b;

short dp[MAXL+3][MAXL+3];

int fn(int i1, int i2)
{
    if(i1 == len_a || i2 == len_b)
        return abs(len_a+i2-i1 - len_b);

    if(dp[i1][i2] != -1) return dp[i1][i2];

    int mn = 0;

    if(a[i1] == b[i2])
        mn = fn(i1+1, i2+1);
    else      // INS, DEL, REP
        mn = 1 + min(fn(i1, i2+1), min(fn(i1+1, i2), fn(i1+1, i2+1)));

    return dp[i1][i2] = mn;
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> a >> b;

        len_a = a.length(), len_b = b.length();

        fill(&dp[0][0], &dp[MAXL+3][0], -1);

        cout << fn(0, 0) << '\n';
    }

    return 0;
}
