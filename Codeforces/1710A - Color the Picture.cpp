// ==================================================
// Problem  :   1710A - Color the Picture
// Run time :   0.046 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


bool canColor(int dim1, int dim2, const vector<int> &a)
{
    int stripeSum = 0;
    int extraStripeCount = 0;

    for (int i = 0; i < a.size() and stripeSum < dim1; ++i) {
        int currStripeCount = a[i] / dim2;
        if (currStripeCount < 2) continue;

        int canTake = min(dim1 - stripeSum, currStripeCount);
        stripeSum += canTake;
        extraStripeCount += canTake - 2;

        if (dim1 - stripeSum == 1) {
            if (extraStripeCount > 0) {
                --extraStripeCount;
                --stripeSum;
            } else {
                stripeSum -= 2;     // Drop a pigment
            }
        }
    }

    return stripeSum == dim1;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        vector<int> a(k, 0);

        for (auto &val : a) {
            scanf("%d", &val);
        }

        bool ans = canColor(n, m, a) || canColor(m, n, a);

        printf("%s\n", ans? "Yes" : "No");
    }
    
    return 0;
}
