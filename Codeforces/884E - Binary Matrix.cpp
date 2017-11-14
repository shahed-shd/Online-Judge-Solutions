// ==================================================
// Problem  :   884E - Binary Matrix
// Run time :   2.573 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
using namespace std;


const int MAXN = (1 << 14) + 3;


void hex_to_bin_process(char str[], bitset<MAXN> &row)
{
    char ss[2] = " ";
    int val;

    for(int i = 0; str[i]; ++i) {
        ss[0] = str[i];
        sscanf(ss, "%x", &val);

        row[i * 4 + 1] = val & 0b1000;
        row[i * 4 + 2] = val & 0b100;
        row[i * 4 + 3] = val & 0b10;
        row[i * 4 + 4] = val & 1;
    }
}


int build_parent(int m, int par[], bitset<MAXN> &row)
{
    int groupCnt = 0;

    if(row[1])
        par[1] = 1, ++groupCnt;

    for(int i = 2; i <= m; ++i) {
        if(row[i]) {
            if(row[i-1]) par[i] = par[i-1];
            else par[i] = i, ++groupCnt;
        }
    }

    return groupCnt;
}


int find_parent(int par[], int x)
{
    return ((par[x] == x)? x : par[x] = find_parent(par, par[x]));
}


int merge_with_prev_row(int m, bitset<MAXN> &currRow, bitset<MAXN> &prevRow, int currPar[], int prevPar[])
{
    int gParent[MAXN] = {0}, mergeCnt = 0;

    for(int i = 1; i <= m; ++i) {
        if(currRow[i] and prevRow[i]) {
            int cp = find_parent(currPar, i);
            int pp = find_parent(prevPar, i);

            if(gParent[pp]  == 0) {
                gParent[pp] = cp;
                ++mergeCnt;
            }
            else if(gParent[pp] != cp) {
                currPar[cp] = gParent[pp];
                ++mergeCnt;
            }
        }
    }

    return mergeCnt;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    char str[MAXN/4 + 3];
    bitset<MAXN> matRow[2];
    int currId = 1;

    int parent[2][MAXN] = {};

    int ans = 0;

    for(int i = 1; i <= n; ++i, currId = 1 - currId) {
        scanf("%s", str);
        hex_to_bin_process(str, matRow[currId]);

        ans += build_parent(m, parent[currId], matRow[currId]);
        ans -= merge_with_prev_row(m, matRow[currId], matRow[1-currId], parent[currId], parent[1-currId]);
    }

    printf("%d\n", ans);

    return 0;
}
