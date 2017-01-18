// ==================================================
// Problem  :   1393 - Crazy Calendar
// Run time :   0.092 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int T = fastIn<int>();

    for(int tc = 1; tc <= T; ++tc) {
        int r = fastIn<int>(), c = fastIn<int>();

        int stoneNum, lowerRight = r+c-2, nim = 0;

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                stoneNum = fastIn<int>();

                if((lowerRight - (i+j)) & 1) nim ^= stoneNum;
            }
        }

        printf("Case %d: %s\n", tc, (nim)? "win" : "lose");
    }

    return 0;
}
