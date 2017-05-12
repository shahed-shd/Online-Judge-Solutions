// ==================================================
// Problem  :   1044 - Palindrome Partitioning
// Run time :   0.068 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cstring>
using namespace std;

const int MAXN = 1000 + 3;

int memo[MAXN];
bitset<MAXN> isPalindrome[MAXN];

int main()
{
    int t;
    scanf("%d", &t);

    char str[MAXN];

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%s", str);

        int len = strlen(str);

        for(int i = 0; i < len; ++i)
            isPalindrome[i][i] = true;

        for(int L = 2; L <= len; ++L) {
            for(int i1 = 0; i1 < len-L+1; ++i1) {
                int i2 = i1 + L - 1;

                if(L == 2) isPalindrome[i1][i2] = str[i1] == str[i2];
                else isPalindrome[i1][i2] = str[i1] == str[i2] and isPalindrome[i1+1][i2-1];
            }
        }

        for(int i = 0; i < len; ++i) {
            if(isPalindrome[0][i])
                memo[i] = 1;
            else {
                memo[i] = INT_MAX;

                for(int j = 0; j < i; ++j)
                    if(isPalindrome[j+1][i] and 1+memo[j] < memo[i])
                        memo[i] = 1 + memo[j];
            }
        }

        printf("Case %d: %d\n", tc, memo[len-1]);
    }

    return 0;
}
