#include <cstdio>
#include <cstring>
using namespace std;

typedef     long long       LL;

const int MAXL = 20;

LL fact[MAXL+1];

int main()
{
    //freopen("in", "r", stdin);

    fact[0] = 1;
    for(int i = 1; i <= MAXL; ++i)
        fact[i] = fact[i-1] * i;

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        char str[MAXL+5];
        int n;
        scanf("%s %d", str, &n);

        printf("Case %d: ", tc);

        int len = strlen(str);
        int cntLetters[26] = {0};

        for(int i = 0; i < len; ++i)
            ++cntLetters[str[i] - 'a'];

        LL permutation = fact[len];
        for(int i = 0; i < 26; ++i)
            if(cntLetters[i] > 1)
                permutation /= cntLetters[i];

        if(n > permutation) {
            puts("Impossible");
            continue;
        }

        int nowLen = 0;
        int alreadyPassed = 0;

        while(nowLen < len) {
            for(int i = 0; i < 26; ++i) {
                if(cntLetters[i]) {
                    --cntLetters[i];
                    permutation = fact[len - nowLen - 1];

                    for(int j = 0; j < 26; ++j)
                        if(cntLetters[j] > 1)
                            permutation /= fact[cntLetters[j]];

                    if(n <= alreadyPassed + permutation) {
                        ++nowLen;
                        putchar('a'+i);
                        break;
                    }
                    else {
                        ++cntLetters[i];
                        alreadyPassed += permutation;
                    }
                }
            }
        }

        putchar('\n');
    }

    return 0;
}
