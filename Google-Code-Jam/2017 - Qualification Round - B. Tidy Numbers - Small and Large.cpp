// ==================================================
// Round    :   Google Code Jam 2017 - Qualification Round
// Problem  :   B. Tidy Numbers
// Size     :   Small, Large
// Point    :   5 + 15
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 30;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    char num[MAXL];

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%s", num);

        int len = strlen(num);

        for(int i = 1; i < len; ++i) {
            if(num[i-1] > num[i]) {
                int j;

                for(j = i-1; j > 0; --j) {
                    if(num[j] > '1' and num[j-1] <= num[j]-1) {
                        break;
                    }
                }

                --num[j];

                for(i = j+1; i < len; ++i)
                    num[i] = '9';
            }
        }

        printf("Case #%d: ", tc);

        for(int i = 0; true; ++i) {
            if(num[i] != '0') {
                puts(num+i);
                break;
            }
        }
    }

    return 0;
}
