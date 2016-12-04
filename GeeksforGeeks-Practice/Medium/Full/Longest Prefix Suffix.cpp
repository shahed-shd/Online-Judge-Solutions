// ==================================================
// Problem  :   Longest Prefix Suffix
// Run time :   0.069 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 100000 + 3;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    char str[MAXL];
    int lps[MAXL];

    while(t--) {
        scanf("%s", str);
        int m = strlen(str);

        lps[0] = 0;
        int i = 1, len = 0;

        while(i < m) {
            if(str[i] == str[len]) {
                lps[i++] = ++len;
            }
            else {
                if(len) len = lps[len-1];
                else lps[i++] = 0;
            }
        }

        printf("%d\n", lps[m-1]);
    }

    return 0;
}
