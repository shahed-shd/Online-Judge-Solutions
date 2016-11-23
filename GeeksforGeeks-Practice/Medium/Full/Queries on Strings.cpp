// ==================================================
// Problem  :   Queries on Strings
// Run time :   0.106 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 10000 + 3;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    char str[MAXL];

    while(t--) {
        scanf("%s", str+1);
        int len = strlen(str+1);

        int memo[26][MAXL] = {{0}};

        for(int i = 1; i <= len; ++i) {
            ++memo[str[i]-'a'][i];

            for(int j = 0; j < 26; ++j)
                memo[j][i] += memo[j][i-1];
        }

        int q, L, R, ans;
        scanf("%d", &q);

        while(q--) {
            scanf("%d %d", &L, &R);

            ans = 0;
            for(int i = 0; i < 26; ++i)
                if(memo[i][R] - memo[i][L-1]) ++ans;

            printf("%d", ans);
            if(q) putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
