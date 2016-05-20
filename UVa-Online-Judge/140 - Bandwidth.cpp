#include <cstdio>
#include <algorithm>
#include <bitset>
#include <map>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

const int MAXN = 8+3;

bitset<MAXN> adjMat[MAXN];
map<char, int> id;
string id_char;
int n, minBandwith;
string backtrackStr, ansStr;

inline bool bitcheck(int n, int pos) { return (n>>pos) & 1; }
inline int biton(int n, int pos) { return n | (1<<pos); }

int get_id(char ch)
{
    if(id.find(ch) == id.end()) {
        id[ch] = n++;
        id_char.push_back(ch);
    }

    return id[ch];
}

int get_bandwith(int u, int pos)
{
    int ret = 0;

    for(int v = 0; v < n; ++v) {
        if(adjMat[u][v]) {
            for(int i = 0; i < n; ++i) {
                if(backtrackStr[i] == v) {
                    ret = max(ret, abs(pos - i));
                    break;
                }
            }
        }
    }

    return ret;
}

void fn(int mask)
{
    if(mask == (1<<n)-1) {
        int bw = 0;
        for(int i = 0; i < n; ++i)
            bw = max(bw, get_bandwith(backtrackStr[i], i));

        if(bw < minBandwith) {
            minBandwith = bw;
            ansStr = backtrackStr;
        }
        else if(bw == minBandwith) {
            for(int i = 0; i < n; ++i) {
                if(id_char[ansStr[i]] > id_char[backtrackStr[i]]) {
                    ansStr = backtrackStr;
                    break;
                }
                else if(id_char[ansStr[i]] < id_char[backtrackStr[i]])
                    break;
            }
        }

        return;
    }

    for(int i = 0; i < n; ++i) {
        if(!bitcheck(mask, i)) {
            backtrackStr.push_back(i);
            fn(biton(mask, i));
            backtrackStr.pop_back();
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    char input[100];

    while(scanf("%s", input), input[0] !=  '#') {
        id.clear();
        id_char.clear();
        for(int i = 0; i < MAXN; ++i) adjMat[i].reset();
        n = 0;

        int len = strlen(input);

        for(int i = 0; i < len; ++i) {
            int u = get_id(input[i]);

            for(i+=2; input[i] != ';' && i < len; ++i) {
                int v = get_id(input[i]);
                adjMat[u][v] = adjMat[v][u] = true;
            }
        }

        minBandwith = INT_MAX;
        backtrackStr.clear();
        ansStr.clear();
        fn(0);

        for(auto& x : ansStr)
            printf("%c ", id_char[x]);

        printf("-> %d\n", minBandwith);
    }

    return 0;
}
