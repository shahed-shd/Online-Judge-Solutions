// ==================================================
// Problem  :   Anagram
// Score    :   25 /25
// Language :   C++14
// ==================================================

#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;


const int MAXL = 1e4 + 3;

int main()
{
    int t;
    scanf("%d", &t);

    char ss[MAXL];

    while(t--) {
        scanf("%s", ss);

        int len = strlen(ss);

        if(len & 1) {
            puts("-1");
            continue;
        }

        int count1[26+3] = {0}, count2[26+3] = {0};
        int k = len / 2;


        for(int i = 0; i < k; ++i) ++count1[ss[i] - 'a'];
        for(int i = k; i < len; ++i) ++count2[ss[i] - 'a'];

        int ans = 0;

        for(int i = 0; i < 26; ++i) ans += abs(count1[i] - count2[i]);

        ans /= 2;

        printf("%d\n", ans);
    }

    return 0;
}
