// ==================================================
// Problem  :   Gemstones
// Score    :   20 /20
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    char s[110];
    int cnt[30] = {0};

    for(int i = 0; i < n; ++i) {
        scanf("%s", s);

        int len = strlen(s);
        sort(s, s+len);

        int i1 = 0, i2 = 0;
        ++cnt[s[i1]-'a'];

        while(++i2 < len) {
            if(s[i1] != s[i2]) {
                i1 = i2;
                ++cnt[s[i1]-'a'];
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < 26; ++i)
        if(cnt[i] == n) ++ans;

    printf("%d\n", ans);

    return 0;
}
