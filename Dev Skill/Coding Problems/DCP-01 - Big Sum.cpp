// ==================================================
// Problem  :   DCP-01 - Big Sum
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXL = 100 + 10;

int main()
{
    //freopen("in", "r", stdin);

    char a[MAXL], b[MAXL], res[MAXL];

    while(scanf("%[^,],%s\n", a, b) != EOF) {
        int len_a = strlen(a), len_b = strlen(b);
        int len = max(len_a, len_b);
        int x1, x2, carry = 0;

        for(int i = 0; i < len; ++i) {
            x1 = (i < len_a)? a[i]-'0' : 0;
            x2 = (i < len_b)? b[i]-'0' : 0;

            carry += x1 + x2;

            res[i] = (carry % 10) + '0';
            carry /= 10;
        }

        while(carry) {
            res[len++] = (carry % 10) + '0';
            carry /= 10;
        }

        res[len] = '\0';

        int i;
        for(i = 0; res[i] == '0'; ++i);

        puts(res+i);
    }

    return 0;
}
