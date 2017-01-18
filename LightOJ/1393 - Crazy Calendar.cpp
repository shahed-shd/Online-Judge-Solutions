// ==================================================
// Problem  :   1393 - Crazy Calendar
// Run time :   0.104 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; ++tc) {
        int r, c;
        scanf("%d %d", &r, &c);

        int stoneNum, lowerRight = r + c - 2;
        int nim = 0;

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                scanf("%d", &stoneNum);

                if((lowerRight - (i+j)) & 1) nim ^= stoneNum;
            }
        }

        printf("Case %d: %s\n", tc, (nim)? "win" : "lose");
    }

    return 0;
}
