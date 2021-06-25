// ==================================================
// Problem  :   1538G - Gift Set
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


typedef     long long       LL;

int x, y, a, b;


bool check(int n)
{
    int start = 0, end = n;

    while (start <= end) {
        LL mid = (start + end) / 2;

        LL redUsed = b * LL(n) + (a - b) * mid;
        LL blueUsed = a * LL(n) + (b - a) * mid;

        if (redUsed <= x && blueUsed <= y) {
            return true;
        }

        if (redUsed > x && blueUsed > y) {
            return false;
        }

        if (redUsed > x) {
            if (a > b) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        else {  // blueUsed > y
            if (b > a) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
    }

    return false;
}


int binSearch(int start, int end)
{
    int ans = 0;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (check(mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d", &x, &y, &a, &b);
        printf("%d\n", binSearch(0, min(x, y)));
    }

    return 0;
}
