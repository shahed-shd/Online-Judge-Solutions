// ==================================================
// Problem  :   12700 - Banglawash
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        char str[20];
        scanf("%s", str);

        int b_cnt = 0, w_cnt = 0, t_cnt = 0, a_cnt = 0;

        for(int i = 0; i < n; ++i) {
            if(str[i] == 'B') ++b_cnt;
            else if(str[i] == 'W') ++w_cnt;
            else if(str[i] == 'T') ++t_cnt;
            else ++a_cnt;
        }

        printf("Case %d: ", tc);

        if(n == a_cnt) {
            puts("ABANDONED");
        }
        else if(n - a_cnt == b_cnt) {
            puts("BANGLAWASH");
        }
        else if(n - a_cnt == w_cnt) {
            puts("WHITEWASH");
        }
        else if(b_cnt == w_cnt) {
            printf("DRAW %d %d\n", b_cnt, t_cnt);
        }
        else if(b_cnt > w_cnt) {
            printf("BANGLADESH %d - %d\n", b_cnt, w_cnt);
        }
        else if(w_cnt > b_cnt) {
            printf("WWW %d - %d\n", w_cnt, b_cnt);
        }
    }

    return 0;
}
