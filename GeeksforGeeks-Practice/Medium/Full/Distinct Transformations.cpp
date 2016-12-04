// ==================================================
// Problem  :   Distinct Transformations
// Run time :   0.069 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXLA = 1000 + 3;
const int MAXLB = 100 + 3;

int memo[MAXLB][MAXLA] = {{0}};

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    char strA[MAXLA], strB[MAXLB];

    while(t--) {
        scanf("%s %s", strA+1, strB+1);

        int lenA = strlen(strA+1), lenB = strlen(strB+1), tmp;

        for(int i = 1; i <= lenB; ++i) {
            for(int j = 1; j <= lenA; ++j) {
                tmp = strB[i] == strA[j];

                if(i > 1) tmp *= memo[i-1][j-1];
                tmp += memo[i][j-1];

                memo[i][j] = tmp;
            }
        }

        printf("%d\n", memo[lenB][lenA]);
    }

    return 0;
}
