// ==================================================
// Problem  :   1114 - Easily Readable
// Run time :   0.248 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXC = 1e5 + 3;
const int MAXL = 10000 + 3;
const int ALPHABET = 52;
const int ROOT = 0;

char word[MAXL];
char sentence[MAXL];

int nxt[MAXC][ALPHABET];
int info[MAXC];
int trieSize;

inline int getId(char ch)
{
    if('A' <= ch && ch <= 'Z') return (ch - 'A');
    return (ch - 'a' + 26);
}

inline void reset_row(int v)
{
    fill(&nxt[v][0], &nxt[v][0]+ALPHABET, 0);
    info[v] = 0;
}

void trie_insert(char str[], int len)
{
    int v = ROOT;

    for(int i = 0; i < len; ++i) {
        int &rf = nxt[v][getId(str[i])];
        if(rf == 0) {
            rf = ++trieSize;
            reset_row(trieSize);
        }
        v = rf;
    }

    ++info[v];
}

int trie_search(char str[], int len)
{
    int v = ROOT;

    for(int i = 0; i < len; ++i) {
        int &rf = nxt[v][getId(str[i])];
        if(rf == 0) return 0;
        v = rf;
    }

    return info[v];
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        trieSize = 0;
        reset_row(ROOT);

        int n;
        scanf("%d", &n);

        while(n--) {
            scanf("%s", word);

            int len = strlen(word);
            if(len > 3) sort(word+1, word+len-1);
            trie_insert(word, len);
        }

        int m;
        scanf("%d", &m);
        getchar();

        printf("Case %d:\n", tc);

        while(m--) {
            fgets(sentence, MAXL, stdin);

            int len = strlen(sentence), res = 1;
            if(sentence[len-1] == '\n') sentence[--len]  = '\0';

            for(int i = 0; i < len; ++i) {
                if(sentence[i] == ' ') continue;
                else {
                    int j;
                    for(j = 0; ('A' <= sentence[i] && sentence[i] <= 'Z') || ('a' <= sentence[i] && sentence[i] <= 'z'); ++i, ++j) {
                        word[j] = sentence[i];
                    }
                    word[j] = '\0';

                    if(j > 3) sort(word+1, word+j-1);

                    res *= trie_search(word, j);

                    if(res == 0) break;
                }
            }

            printf("%d\n", res);
        }
    }

    return 0;
}
