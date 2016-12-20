// ==================================================
// Problem  :   11450 - Wedding shopping
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

const int MAXM = 200 + 3;

int m;
bool noSol;

void mergeTogether(vector<int> &V1, vector<int> &V2, vector<int> &V3)
{
    bitset<MAXM> isTaken;

    for(auto &x1 : V1) {
        for(auto &x2 : V2) {
            if(x1+x2 <= m && !isTaken[x1+x2]) {
                isTaken[x1+x2] = true;
                V3.push_back(x1+x2);
            }
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int c, k, tmp;
        scanf("%d %d", &m, &c);

        noSol = false;
        vector<int> V1, V2, V3;

        scanf("%d", &k);
        for(int i = 0; i < k; ++i) {
            scanf("%d", &tmp);
            if(tmp <= m) V1.push_back(tmp);
        }

        if(V1.empty()) noSol = true;

        for(int i = 1; i < c; ++i) {
            scanf("%d", &k);
            V2.clear();

            for(int j = 0; j < k; ++j) {
                scanf("%d", &tmp);
                if(tmp <= m) V2.push_back(tmp);
            }

            if(V2.empty() || noSol) {
                noSol = true;
                continue;
            }

            V3.clear();
            mergeTogether(V1, V2, V3);

            if(V3.empty()) noSol = true;
            V1 = V3;
        }

        if(noSol) puts("no solution");
        else printf("%d\n", *max_element(V1.begin(), V1.end()));
    }

    return 0;
}
