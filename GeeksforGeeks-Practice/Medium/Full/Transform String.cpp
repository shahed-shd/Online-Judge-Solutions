// ==================================================
// Problem  :   Transform String
// Run time :   0.074 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 1e5 + 3;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    char strA[MAXL], strB[MAXL];

    while(t--) {
        scanf("%s %s", strA, strB);

        int lenA = strlen(strA), lenB = strlen(strB);

        if(lenA != lenB) {
            puts("-1");
            continue;
        }

        int letterCnt[26] = {0};

        for(int i = 0; i < lenA; ++i) {
            ++letterCnt[strA[i]-'a'];
            --letterCnt[strB[i]-'a'];
        }

        bool unequalFound = false;

        for(int i = 0; i < 26; ++i) {
            if(letterCnt[i]) {
                unequalFound = true;
                break;
            }
        }

        if(unequalFound) {
            puts("-1");
            continue;
        }

        int j = lenA, matchCnt = 0;

        for(int i = lenB-1; i >= 0; --i) {
            if(j > 0) {
                while(j > 0 && strB[i] != strA[--j]);
                if(strB[i] == strA[j]) ++matchCnt;
            }
            else break;
        }

        printf("%d\n", lenA - matchCnt);
    }

    return 0;
}
