// ==================================================
// Problem  :   10038 - Jolly Jumpers
// Run time :   0.000 sec
// Language :   C++11
// ==================================================


#include <cstdio>
#include <bitset>
using namespace std;

const int MAXN = 3000 + 3;

bitset<MAXN> flag;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;

    while (scanf("%d", &n) == 1) {
        flag.reset();

        int prevValue;
        scanf("%d", &prevValue);

        bool isJolly = true;

        for (int i = 1; i < n; ++i) {
            int currValue;
            scanf("%d", &currValue);

            if (isJolly) {
                int absDiff = abs(prevValue - currValue);

                if (1 <= absDiff && absDiff < n) {
                    flag[absDiff] = true;
                } else {
                    isJolly = false;
                }
            }

            prevValue = currValue;
        }

        isJolly = isJolly && flag.count() == n - 1;

        printf("%s\n", isJolly ? "Jolly" : "Not jolly");
    }

    return 0;
}
