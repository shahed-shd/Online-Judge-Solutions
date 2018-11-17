// ==================================================
// Problem  :   1077B - Disturbed People
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <bitset>
using namespace std;

const int MAXN = 100 + 3;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    bitset<MAXN> state;
    int a;

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        state[i] = a;
    }

    int ans = 0;

    for(int i = 2; i < n; ++i) {
        if((!state[i]) and state[i-1] and state[i+1]) {
            state[i+1] = 0;
            ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}
