#include <cstdio>
#include <algorithm>
#include <bitset>
#include <utility>
#include <cstring>
using namespace std;

typedef     long long       LL;
typedef     pair<LL,LL>     pLL;

const int MAXL = 31+3;

pLL memo[MAXL][2];

pLL fnnn(int idx, bool prev)
{
    if(idx == 0) return pLL(0, 1);      // 0 adjacent bit & 1 number formed.

    pLL &ret = memo[idx][prev];
    if(ret.first != -1) return ret;

    pLL zero = fnnn(idx-1, 0);
    pLL one = fnnn(idx-1, 1);

    ret.first = zero.first + one.first + ((prev)? one.second : 0);
    ret.second = zero.second + one.second;

    return ret;
}

LL fn(LL n)
{
    ++n;

    bitset<MAXL> bits(n);
    char str[MAXL+3];
    strcpy(str, bits.to_string().c_str());

    for(int i = 0; ; ++i) {     // Erasing leading zeros.
        if(str[i] == '1') {
            int goBack = i;
            while(str[i]) {
                str[i-goBack] = str[i];
                ++i;
            }
            str[i-goBack] = '\0';
            break;
        }
    }

    int len = strlen(str);

    pLL res;
    LL adjBitCnt = 0;
    bool prev = 0;
    LL cnt = 0;

    for(int i = 0; str[i]; ++i) {
        int d = str[i] - '0';

        if(d == 1) {
            res = fnnn(len-1, 0);
            adjBitCnt += res.first;
        }

        if(cnt && d) adjBitCnt += res.second * cnt;

        if(prev && d) ++cnt;

        prev = d;
        --len;
    }

    return adjBitCnt;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    fill(&memo[0][0], &memo[MAXL][0], pLL(-1, -1));

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        printf("Case %d: %lld\n", tc, (n)? fn(n) : 0);
    }

    return 0;
}
