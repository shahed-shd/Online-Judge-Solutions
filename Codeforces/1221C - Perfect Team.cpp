// ==================================================
// Problem  :   1221C - Perfect Team
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


int c, m, x;


bool canFormPerfectTeam(int n) {
    int rem = 0;
    if(c >= n) {
        rem += c - n;
        if(m >= n) {
            rem += m - n;
            if(rem + x >= n) {
                return true;
            }
        }
    }

    return false;
}


int binSearch(int s, int t) {
    int res = 0;

    while(s <= t) {
        int mid = (s + t) / 2;

        if(canFormPerfectTeam(mid)) {
            res = mid;
            s = mid + 1;
        } else {
            t = mid - 1;
        }
    }

    return res;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int q;
    scanf("%d", &q);

    while(q--) {
        scanf("%d %d %d", &c, &m, &x);
        printf("%d\n", binSearch(1, min(c, m)));
    }

    return 0;
}
