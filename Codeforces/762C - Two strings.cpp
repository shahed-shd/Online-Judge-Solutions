// ==================================================
// Problem  :   762C - Two strings
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 3;

char a[MAXN], b[MAXN];
int pre[MAXN], suf[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%s %s", a+1, b+1);

    int lenA = strlen(a+1), lenB = strlen(b+1);

    for(int i = 1, j = 1; i <= lenB; ++i) {
        while(j <= lenA && b[i] != a[j]) ++j;

        pre[i] = j;
        ++j;
    }

    for(int i = lenB, j = lenA; i >= 1; --i) {
        while(j >= 1 && b[i] != a[j]) --j;

        suf[i] = lenA - j + 1;
        --j;
    }

    pre[0] = 0, suf[lenB+1] = 0;

    int p1 = 0, p2 = 1;
    int pp1, pp2, mx = 0;

    while(p1 <= lenB && p2 <= lenB+1) {
        int sum = pre[p1] + suf[p2];

        if(sum <= lenA) {
            int len = p1 + lenB-p2+1;

            if(len > mx && len <= lenB) {
                mx = len;
                pp1 = p1, pp2 = p2;
            }

            ++p1;
        }
        else {
            ++p2;
        }
    }

    if(mx) {
        for(int i = 1; i <= pp1; ++i) putchar(b[i]);
        for(int i = pp2; i <= lenB; ++i) putchar(b[i]);
    }
    else  puts("-");

    return 0;
}
