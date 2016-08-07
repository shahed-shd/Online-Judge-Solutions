// ==================================================
// Problem  :   158A - Next Round
// Run time :   0.060 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    int n, k;

    while(~scanf("%d %d", &n, &k)) {
        int scores[n];

        for(int i = 0; i < n; ++i)
            scanf("%d", scores+i);

        int i = --k;

        if(scores[k]) {
            while(++i < n && scores[k] == scores[i]);
        }
        else {
            while(!scores[--i]);
            ++i;
        }

        printf("%d\n", i);
    }

    return 0;
}
