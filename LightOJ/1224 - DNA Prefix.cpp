// ==================================================
// Problem  :   1224 - DNA Prefix
// Run time :   0.200 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXL = 50 + 3;
const int MAXV = 50000 * 50 + 3;
const int ALPHABET = 4;     // A, C, G, T

int nxt[MAXV][ALPHABET];
int info[MAXV], mx;
int trieSize;

inline int getID(char ch)
{
    if(ch == 'A') return 0;
    if(ch == 'C') return 1;
    if(ch == 'G') return 2;
    return 3;
}

inline void reset_row(int v)
{
    fill(&nxt[v][0], &nxt[v][0]+ALPHABET, 0);
    info[v] = 0;
}

void trie_insert(char str[])
{
    int v = 0;

    for(int i = 0; str[i]; ++i) {
        int &rf = nxt[v][getID(str[i])];
        if(rf == 0) {
            rf = ++trieSize;
            reset_row(trieSize);
        }
        v = rf;

        info[v] += i+1;
        mx = max(mx, info[v]);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        reset_row(0);
        trieSize = 0, mx = 0;
        char str[MAXL];

        while(n--) {
            scanf("%s", str);
            trie_insert(str);
        }

        printf("Case %d: %d\n", tc, mx);
    }

    return 0;
}
