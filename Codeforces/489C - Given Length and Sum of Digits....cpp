// ==================================================
// Problem  :   489C - Given Length and Sum of Digits...
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int m, s;

    while(~scanf("%d %d", &m, &s)) {
        if((m > 1 && s == 0) || (s > m*9)) {
            puts("-1 -1");
            continue;
        }

        if(m == 1 && s == 0) {
            puts("0 0");
            continue;
        }

        int maxNum[m], minNum[m];
        for(int i = 0; i < m; ++i)
            maxNum[i] = minNum[i] = 0;

        int rem = s;

        for(int i = 0; i < m; ++i) {
            if(rem > 9) {
                maxNum[i] = 9;
                rem -= 9;
            }
            else {
                maxNum[i] = rem;
                break;
            }
        }

        minNum[0] = 1;
        rem = s-1;

        for(int i = m-1; i >= 0; --i) {
            if(rem > 9) {
                minNum[i] += 9;
                rem -= 9;
            }
            else {
                minNum[i] += rem;
                break;
            }
        }

        for(int i = 0; i < m; ++i) printf("%d", minNum[i]);
        putchar(' ');
        for(int i = 0; i < m; ++i) printf("%d", maxNum[i]);
        putchar('\n');
    }

    return 0;
}
