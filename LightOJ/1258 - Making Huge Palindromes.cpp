#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXL = 1e6 + 3;

int my_gets(char s[], int sz)
{
    fgets(s, sz, stdin);
    int sLen = strlen(s);

    if(s[sLen-1] == '\n')
        s[sLen-1] = '\0', --sLen;

    return sLen;
}

void computeLPSArray(char s[], int m, int lps[])
{
    lps[0] = 0;
    int len = 0;

    for(int i = 1; i < m; ) {
        if(s[i] == s[len]) {
            lps[i++] = ++len;
        }
        else {
            if(len) len = lps[len-1];
            else lps[i++] = 0;
        }
    }
}

int KMPSearch(char str[], int n, char revStr[], int m)
{
    int lps[m+3];
    computeLPSArray(revStr, m, lps);

    int j = 0;

    for(int i = 0; i < n; ) {
        if(str[i] == revStr[j]) {
            ++i, ++j;
        }
        if(i+j == n || i+j == n+1) {
            return i-j;
        }

        if(i < n && str[i] != revStr[j]) {
            if(j) j = lps[j-1];
            else ++i;
        }
    }

    return 0;   // just to avoid warning while compiling.
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d\n", &t);

    for(int tc = 1; tc <= t; ++tc) {
        char str[MAXL];
        int len = my_gets(str, sizeof(str));

        char revStr[MAXL];
        reverse_copy(str, str+len, revStr);

        printf("Case %d: %d\n", tc, len + KMPSearch(str, len, revStr, len));
    }

    return 0;
}
