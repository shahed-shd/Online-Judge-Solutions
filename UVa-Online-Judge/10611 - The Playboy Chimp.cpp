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


// -------------------- Alternatively --------------------
// Run time : 0.010 sec.
/*
#include <cstdio>
using namespace std;

const int MAXN = 50000 + 3;

void binSearch(int arr[], int sz, int val, int &a, int &b)
{
    int s = 0, t = sz - 1;

    while(s <= t) {
        int mid = (s + t) >> 1;

        if(arr[mid] == val) {
            a = mid-1, b = mid+1;
            return;
        }

        if(arr[mid] < val)
            s = mid + 1;
        else
            t = mid - 1;
    }

    a = t, b = s;
}

int main()
{
    int n, chimps[MAXN];

    while(scanf("%d", &n) != EOF) {
        int h, sz = 0, last = -1;

        while(n--) {
            scanf("%d", &h);

            if(h != last)
                chimps[sz++] = last = h;   // Keeps only the unique elements.
        }

        int q, a, b;
        scanf("%d", &q);

        while(q--) {
            scanf("%d", &h);

            binSearch(chimps, sz, h, a, b);

            (a >= 0)? printf("%d ", chimps[a]) : printf("X ");
            (b < sz)? printf("%d\n", chimps[b]) : puts("X");
        }
    }

    return 0;
}
*/
