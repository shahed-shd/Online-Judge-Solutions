// ==================================================
// Problem  :   1129 - Consistency Checker
// Run time :   0.056 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAXV = 10000 * 10 + 3;
const int ALPHABET = 10;        // 0 to 9

int nxt[MAXV][ALPHABET];
int trieSize;
bitset<MAXV> isEnd;

inline void reset_row(int v)
{
    fill(&nxt[v][0], &nxt[v][0]+ALPHABET, 0);
    isEnd[v] = false;
}

bool trie_insert(char num[])
{
    int v = 0;

    for(int i = 0; num[i]; ++i) {
        int &rf = nxt[v][num[i]-'0'];
        if(rf == 0) {
            rf = ++trieSize;
            reset_row(trieSize);
        }

        v = rf;
        if(isEnd[v]) return false;
    }

    isEnd[v] = true;

    return (v == trieSize);
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
        trieSize = 0;
        char num[15];
        bool isConsistent = true;

        while(n--) {
            scanf("%s", num);
            if(!isConsistent) continue;
            isConsistent = trie_insert(num);
        }

        printf("Case %d: %s\n", tc, ((isConsistent)? "YES" : "NO"));
    }

    return 0;
}
