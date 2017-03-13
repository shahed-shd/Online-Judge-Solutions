// ==================================================
// Problem  :   Bandwidth of a matrix
// Runtime  :   0.080 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int nn = n * n, zCnt = 0;
        char ch[2];

        while(nn--) {
            scanf("%s", ch);
            if(ch[0] == '0') ++zCnt;
        }

        int ans = n-1;

        for(int i = 1; i < n; ++i) {
            if(i*(i+1) <= zCnt) --ans;
            else break;
        }

        printf("%d\n", ans);
    }

    return 0;
}
