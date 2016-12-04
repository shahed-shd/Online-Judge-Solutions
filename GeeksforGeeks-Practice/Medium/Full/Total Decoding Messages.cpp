// ==================================================
// Problem  :   Total Decoding Messages
// Run time :   0.060 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 40 + 3;

int memo[MAXN];

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    char str[MAXN];

    while(t--) {
        int n;
        scanf("%d %s", &n, str);

        memo[n] = 1;
        memo[n-1] = str[n-1] != '0';

        for(int i = n-2; i >= 0; --i) {
            if(str[i] == '0') {
                memo[i] = 0;
            }
            else {
                memo[i] = memo[i+1];
                if((str[i]-'0')*10+(str[i+1]-'0') <= 26) memo[i] += memo[i+2];
            }
        }

        printf("%d\n", memo[0]);
    }

    return 0;
}
