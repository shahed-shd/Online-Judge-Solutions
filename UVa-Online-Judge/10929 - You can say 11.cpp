// ==================================================
// Problem  :   10929 - You can say 11
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;


const int MAXL = 1000 + 3;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char num[MAXL];
    int len;

    while(scanf("%[^\n]\n", num), len = strlen(num), !(num[0] == '0' and len == 1)) {
        int res = 0;

        for(int i = 0; i < len; ++i) {
            int digit = num[len - i - 1] - '0';
            res += digit * ((i & 1)? 10 : 1);
        }

        res %= 11;

        printf("%s is%sa multiple of 11.\n", num, ((res)? " not " : " "));
    }

    return 0;
}
