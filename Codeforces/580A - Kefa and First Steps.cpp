// ==================================================
// Problem  :   580A - Kefa and First Steps
// Run time :   0.031 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    while(~scanf("%d", &n)) {
        int ai, prev, start = 0, maxLen = 0;

        scanf("%d", &prev);

        for(int i = 1; i < n; ++i) {
            scanf("%d", &ai);

            if(prev > ai) {
                maxLen = max(maxLen, i - start);
                start = i;
            }

            prev = ai;
        }

        maxLen = max(maxLen, n-start);

        printf("%d\n", maxLen);
    }

    return 0;
}
