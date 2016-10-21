// ==================================================
// Problem  :   727D - T-shirts Distribution
// Run time :   0.031 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstring>
using namespace std;

#define         ff                  first
#define         ss                  second

typedef         pair<int,int>       ii;
typedef         pair<ii,int>        iii;

enum sizes {S = 0, M, L, XL, XXL, XXXL};

inline int str_to_sizes(char str[])
{
    if(str[0] == 'S') return S;
    if(str[0] == 'M') return M;
    if(str[0] == 'L') return L;
    if(str[1] == 'L') return XL;
    if(str[2] == 'L') return XXL;
    return XXXL;
}

inline void getTshirSize(int &a, int &b)
{
    char str[10];
    fgets(str, sizeof(str), stdin);

    a = str_to_sizes(str);
    b = -1;

    int upto = strlen(str)-1;

    for(int i = 1 ; i < upto; ++i) {
        if(str[i] == ',') {
            b = str_to_sizes(&str[i+1]);
            break;
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int tshirts[6], n;

    for(int i = 0; i < 6; ++i)
        scanf("%d", tshirts+i);

    scanf("%d\n", &n);

    if(n > accumulate(tshirts, tshirts+6, 0)) {
        puts("NO");
        return 0;
    }

    int s1, s2;
    vector<int> allocatedTshirts(n);
    vector<iii> choices;

    for(int i = 0; i < n; ++i) {
        getTshirSize(s1, s2);

        if(s2 == -1) {
            allocatedTshirts[i] = s1;
            --tshirts[s1];
        }
        else {
            choices.push_back(iii(ii(s1, s2), i));
        }
    }

    for(int i = 0; i < 6; ++i) {
        if(tshirts[i] < 0) {
            puts("NO");
            return 0;
        }
    }

    sort(choices.begin(), choices.end());

    vector<int> choiceCnt(5, 0);

    for(auto &pr : choices)
        ++choiceCnt[pr.ff.ff];

    int j = 0;

    for(int i = 0; i < 5; ++i) {
        int upto;

        if(tshirts[i] >= choiceCnt[i]) {
            upto = j + choiceCnt[i];

            while(j < upto)
                allocatedTshirts[choices[j++].ss] = i;

            tshirts[i] -= choiceCnt[i];
        }
        else if(tshirts[i] + tshirts[i+1] >= choiceCnt[i]) {
            upto = j + tshirts[i];

            while(j < upto)
                allocatedTshirts[choices[j++].ss] = i;

            upto = j + (choiceCnt[i] - tshirts[i]);

            while(j < upto)
                allocatedTshirts[choices[j++].ss] = i+1;

            tshirts[i+1] -= choiceCnt[i] - tshirts[i];
            tshirts[i] = 0;
        }
        else {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    for(auto &x : allocatedTshirts) {
        if(x == S) puts("S");
        else if(x == M) puts("M");
        else if(x == L) puts("L");
        else if(x == XL) puts("XL");
        else if(x == XXL) puts("XXL");
        else puts("XXXL");
    }

    return 0;
}
