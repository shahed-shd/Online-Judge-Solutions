#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 1e6 + 3;

void computeLPSArray(char b[], int m, int lps[])
{
    lps[0] = 0;
    int len = 0;

    for(int i = 1; i < m; ) {
        if(b[i] == b[len]) {
            lps[i++] = ++len;
        }
        else {
            if(len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
}

int KMPSearch(char a[], char b[])
{
    int n = strlen(a), m = strlen(b);

    int lps[m+3];
    computeLPSArray(b, m, lps);

    int i = 0, j = 0, cnt = 0;

    while(i < n) {
        if(a[i] == b[j]) {
            ++i, ++j;
        }

        if(j == m) {
            ++cnt;
            j = lps[j-1];
        }

        else if(i < n && a[i] != b[j]) {
            if(j != 0) j = lps[j-1];
            else ++i;
        }
    }

    return cnt;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc){
        char a[MAXL], b[MAXL];
        scanf("%s %s", a, b);

        printf("Case %d: %d\n", tc, KMPSearch(a, b));
    }
    return 0;
}
