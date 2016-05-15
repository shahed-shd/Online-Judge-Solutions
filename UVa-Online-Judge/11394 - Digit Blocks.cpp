#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;

typedef     long long   LL;

const int MAXL = 16;

char str[MAXL+5];
int len;
LL memo[1<<MAXL];

inline bool bitcheck(int n, int pos) { return (n>>pos) & 1; }
inline int biton(int n, int pos) { return n | (1<<pos); }

int hexToDec(char ch)
{
    if(ch <= '9') return ch - '0';
    if(ch <= 'Z') return ch - 'A' + 10;
    return ch - 'a' + 10;
}

LL fn(int mask)
{
    if(memo[mask] != -1) return memo[mask];

    int res = 0;
    for(int i = 0; i < len; ++i) {
        if(bitcheck(mask, i)) {
            res += str[i];
            res %= 5;
        }
    }

    LL ret = (res == 0)? 1 : 0;

    bitset<16> isTaken;

    for(int i = 0; i < len; ++i) {
        if(!bitcheck(mask, i) && !isTaken[str[i]]) {
            isTaken[str[i]] = true;
            ret += fn(biton(mask, i));
        }
    }

    return memo[mask] = ret;
}

int main()
{
    while(scanf("%s", str), str[0] != '#') {
        len = strlen(str);

        for(int i = 0; i < len; ++i)
            str[i] = hexToDec(str[i]);

        fill(memo, memo+(1<<MAXL), -1);

        printf("%lld\n", fn(0)-1);
    }

    return 0;
}
