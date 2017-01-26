// ==================================================
// Problem  :   1396 - Palindromic Numbers (III)
// Run time :   0.040 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 1e5 + 3;

char num[MAXL], pal[MAXL];

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%s", num);
        int len = strlen(num);

        int upto = (len+1) >> 1;

        for(int i = 0; i < upto; ++i)
            pal[i] = pal[len-1-i] = num[i];

        pal[len] = '\0';

        int res, carry = 0;

        if(strcmp(num, pal) >= 0) {
            carry = 1;

            for(int i = upto-1; i >= 0 && carry; --i) {
                res = (pal[i]-'0') + carry;
                pal[len-1-i] = pal[i] = (res % 10) + '0';
                carry = res / 10;
            }
        }

        printf("Case %d: ", tc);

        if(carry) {
            pal[len-1] = carry + '0';

            for(int i = 0; i < upto-1; ++i)
                pal[len-2-i] = pal[i];

            printf("%d%s\n", carry, pal);
        }
        else puts(pal);
    }

    return 0;
}
