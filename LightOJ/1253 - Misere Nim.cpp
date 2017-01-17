// ==================================================
// Problem  :   1253 - Misere Nim
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; ++tc) {
        int k;
        scanf("%d", &k);

        int stoneNum, xorRes = 0;
        bool flag = false;

        for(int i = 0; i < k; ++i) {
            scanf("%d", &stoneNum);
            xorRes ^= stoneNum;

            if(stoneNum > 1) flag = true;
        }

        char winner;

        if(flag)
            winner = (xorRes)? 'A' : 'B';
        else
            winner = (k & 1)? 'B' : 'A';

        printf("Case %d: %s\n", tc, (winner == 'A')? "Alice" : "Bob");
    }

    return 0;
}
