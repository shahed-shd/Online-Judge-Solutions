#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXL = 50+3;

char str[MAXL];
int tc, len;
bool bad, good;
unsigned char memo[MAXL][MAXL][MAXL] = {{{0}}};     // As T <= 200, taking unsigned char instead of int.

inline bool isVowel(char ch)
{
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

void fn(int idx, int vCnt, int cCnt)
{
    if(idx == len) {
        (vCnt >= 3 || cCnt >= 5)? bad = true : good = true;
        return;
    }

    unsigned char &reff = memo[idx][vCnt][cCnt];
    if(reff == tc) return;

    if((vCnt >= 3 || cCnt >= 5)) {
        bad = true;
    }
    else if(str[idx] == '?') {
        fn(idx+1, vCnt+1, 0);
        fn(idx+1, 0, cCnt+1);
    }
    else if(isVowel(str[idx])) {
        fn(idx+1, vCnt+1, 0);
    }
    else {
        fn(idx+1, 0, cCnt+1);
    }

    reff = tc;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(tc = 1; tc <= t; ++tc) {
        scanf("%s", str);

        len = strlen(str);
        bad = good = false;

        fn(0, 0, 0);

        printf("Case %d: ", tc);

        if(bad && good) puts("MIXED");
        else if(bad) puts("BAD");
        else puts("GOOD");
    }

    return 0;
}
