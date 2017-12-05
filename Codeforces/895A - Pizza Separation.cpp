// ==================================================
// Problem  :   895A - Pizza Separation
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int pieces[n+3];

    for(int i = 0; i < n; ++i)
        scanf("%d", pieces+i);

    int ans = 360;

    for(int i = 0; i < n; ++i) {
        int sum = 0;

        for(int j = 0; j < n; ++j) {
            sum += pieces[(i+j) % n];
            ans = min(ans, abs(360-sum - sum));
        }
    }

    printf("%d\n", ans);

    return 0;
}
