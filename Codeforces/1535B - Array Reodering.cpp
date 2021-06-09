// ==================================================
// Problem  :   1535B - Array Reodering
// Run time :   0.202 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
using namespace std;


int calc_gcd(int a, int b)
{
    while (b != 0) {
        int m = a % b;
        a = b;
        b = m;
    }

    return a;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        vector<int> odds;
        int val, evenCount = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &val);

            if (val & 1) {
                odds.push_back(val);
            }
            else {
                ++evenCount;
            }
        }

        int ans = evenCount * n - (evenCount * (evenCount + 1) / 2);
        int oddCount = odds.size();

        for (int i = 0; i < oddCount; ++i) {
            for (int j = i + 1; j < oddCount; ++j) {
                ans += calc_gcd(odds[i], odds[j]) > 1;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
