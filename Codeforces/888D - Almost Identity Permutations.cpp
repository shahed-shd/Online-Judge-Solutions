// ==================================================
// Problem  :   888D - Almost Identity Permutations
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <iostream>
using namespace std;


typedef     long long       LL;


int main()
{
    //freopen("in.txt", "r", stdin);

    int n, k;
    cin >> n >> k;

    LL nCr[n+3][n+3] = {{0}};
    int derangement[] = {1, 0, 1, 2, 9, 44, 265};


    // build nCr
    for(int i = 0; i <= n; ++i)
        nCr[i][0] = nCr[i][i] = 1;

    for(int i = 2; i <= n; ++i)
        for(int j = 1; j < i; ++j)
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];

    // Calculate ans.
    LL ans = 0;

    for(int i = k; i >= 0; --i)
        ans += nCr[n][n-i] * derangement[i];

    cout << ans << '\n';

    return 0;
}
