// ==================================================
// Problem  :   10611 - The Playboy Chimp
// Run time :   0.010 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 50000 + 3;

int main()
{
    int n;

    while(scanf("%d", &n) != EOF) {
        vector<int> chimps;
        int h;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &h);
            chimps.push_back(h);
        }

        int first = chimps[0], last = chimps[n-1];

        chimps.erase(unique(chimps.begin(), chimps.end()), chimps.end());   // Keeps only the unique elements.

        int q;
        scanf("%d", &q);

        while(q--) {
            scanf("%d", &h);

            (h <= first)? putchar('X') : printf("%d", *(--lower_bound(chimps.begin(), chimps.end(), h)));
            putchar(' ');
            (last <= h)? putchar('X') : printf("%d", *upper_bound(chimps.begin(), chimps.end(), h));
            putchar('\n');
        }
    }

    return 0;
}
