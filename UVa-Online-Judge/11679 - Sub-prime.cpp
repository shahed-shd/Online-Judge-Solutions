// ==================================================
// Problem  :   11679 - Sub-prime
// Run time :   0.000 sec
// Language :   C++11
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXB = 20 + 3;

int balance[MAXB];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int b, n;

    while (scanf("%d %d", &b, &n), b != 0 && n != 0) {
        for (int i = 1; i <= b; ++i) {
            scanf("%d", balance + i);
        }

        while (n--) {
            int debtor, creditor, debentureValue;
            scanf("%d %d %d", &debtor, &creditor, &debentureValue);
            
            balance[debtor] -= debentureValue;
            balance[creditor] += debentureValue;
        }

        bool ans = !any_of(balance+1, balance+b+1, [](int x) { return x < 0; });

        printf("%c\n", ans ? 'S' : 'N');
    }

    return 0;
}
