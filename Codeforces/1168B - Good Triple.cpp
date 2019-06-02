// ==================================================
// Problem  :   1168B - Good Triple
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


typedef     long long       LL;


const int MAXL = 3e5 + 3;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    char bin_str[MAXL];
    scanf("%s", bin_str);

    int len = strlen(bin_str);
    vector<int> memo(len+1, len);
    LL ans = 0;

    for(int i = len - 1; i >= 0; --i) {
        memo[i] = memo[i+1];

        for(int k = 1; i+2*k < memo[i]; ++k) {
            if(bin_str[i] == bin_str[i+k] and bin_str[i] == bin_str[i+2*k]) {
                memo[i] = i + 2 * k;
                break;
            }
        }

        ans += len - memo[i];
    }

    printf("%lld\n", ans);

    return 0;
}
