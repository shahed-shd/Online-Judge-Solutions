// ==================================================
// Problem  :   2737 - Perfect Rhyme
// Run time :   2.130 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;


const int MAXN = 250000 + 3;
const int MAXL = 30 + 3;
const int ALPHABET = 26;
const int ROOT = 0;

char dict[MAXN][MAXL];

int trie_size;
int nxt[MAXN*MAXL][ALPHABET];
int info[MAXN*MAXL];


void reset_row(int v)
{
    fill(&nxt[v][0], &nxt[v][ALPHABET], 0);
}


void trie_insert(char str[], int len, int idx)
{
    int v = ROOT;

    for(int i = 0; i < len; ++i) {
        int &rf = nxt[v][str[i] - 'a'];

        if(rf == 0) {
            rf = ++trie_size;
            reset_row(trie_size);
        }

        v = rf;
    }

    info[v] = idx;
}


void dfs(int curr_v, int col, int idx_qry_str, int &idx)
{
    if(info[curr_v] != -1) {
        if(info[curr_v] != idx_qry_str) {
            if(idx == -1 or strcmp(&dict[info[curr_v]][0], &dict[idx][0]) < 0) {
                idx = info[curr_v];
            }
        }
    }

    int nxt_v = nxt[curr_v][col];
    if(nxt_v == 0) return;

    for(int i = 0; i < ALPHABET; ++i)
        dfs(nxt_v, i, idx_qry_str, idx);
}


int trie_search(char str[], int len)
{
    vector<int> nxt_seq;
    int v = ROOT;
    int idx_qry_str = -1;

    for(int i = 0; i < len; ++i) {
        int &rf = nxt[v][str[i] - 'a'];

        if(rf == 0) {
            break;
        }

        v = rf;
        nxt_seq.push_back(rf);

        if(i == len-1) idx_qry_str = info[v];
    }

    int idx = -1;

    while(!nxt_seq.empty() and idx == -1) {
        int curr_v = nxt_seq.back(); nxt_seq.pop_back();

        for(int i = 0; i < ALPHABET; ++i) {
            if(nxt[curr_v][i] != 0) {
                dfs(curr_v, i, idx_qry_str, idx);
            }
        }
    }

    return idx;
}


int fgets_wrapper(char str[])
{
    if(fgets(str, MAXL, stdin) == NULL) {
        str[0] = '\0';
        return 0;
    }

    int len = strlen(str);

    if(len > 0 and str[len-1] == '\n') {
        str[len-1] = '\0';
        --len;
    }

    return len;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    // Reset trie.
    trie_size = 0;
    fill(info, info+MAXN*MAXL, -1);

    // Input dictionary words.
    char word[MAXL];
    int len;
    int word_cnt = 0;

    while(len = fgets_wrapper(word), len) {
        strcpy(dict[word_cnt], word);           // Store the word in dictionary.

        reverse(word, word+len);

        trie_insert(word, len, word_cnt);       // Insert the reversed word into trie.
        ++word_cnt;
    }

    // Input the query words.
    while(len = fgets_wrapper(word), len) {
        reverse(word, word+len);

        int idx = trie_search(word, len);

        puts(&dict[idx][0]);
    }

    return 0;
}
