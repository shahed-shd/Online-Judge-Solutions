// ==================================================
// Problem  :   888C - K-Dominant Character
// Run time :   0.031 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;


const int MAXN = 100000 + 3;


int main()
{
    //freopen("in.txt", "r", stdin);

    char str[MAXN];
    scanf("%s", str);

    int recentIdx[26], maxInterval[26] = {0};

    fill_n(recentIdx, 26, -1);

    int len;

    for(len = 0; str[len]; ++len) {
        int x = str[len] - 'a';

        maxInterval[x] = max(maxInterval[x], len - recentIdx[x]);
        recentIdx[x] = len;
    }

    for(int x = 0; x < 26; ++x)
        maxInterval[x] = max(maxInterval[x], len - recentIdx[x]);

    int k = INT_MAX;

    for(int i = 0; i < 26; ++i)
        if(maxInterval[i])
            k = min(k, maxInterval[i]);

    printf("%d\n", k);

    return 0;
}
