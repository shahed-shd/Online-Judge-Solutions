// Run time : 0.000 sec.
#include <cstdio>
#include <algorithm>
using namespace std;

bool my_next_permutation(char str[], int len)
{
    int idx = len-2;
    while(idx >= 0 && str[idx] > str[idx+1]) --idx;

    if(idx < 0) return false;

    int idx2 = idx+1;

    while(idx2 < len && str[idx] < str[idx2]) ++idx2;
    --idx2;

    swap(str[idx], str[idx2]);

    while(++idx < --len) swap(str[idx], str[len]);

    return true;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, k;
        scanf("%d %d", &n, &k);

        char str[30];
        for(int i = 0; i < n; ++i) str[i] = 'A' + i;
        str[n] = '\0';

        printf("Case %d:\n", tc);

        do puts(str);
        while(--k && my_next_permutation(str, n));
    }

    return 0;
}


// -------------------- Alternatively (using STL) --------------------
// Run time : 0.000 sec.
/*
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, k;
        scanf("%d %d", &n, &k);

        char str[30];
        for(int i = 0; i < n; ++i) str[i] = 'A' + i;
        str[n] = '\0';

        printf("Case %d:\n", tc);

        do puts(str);
        while(--k && next_permutation(str, str+n));
    }

    return 0;
}
*/
