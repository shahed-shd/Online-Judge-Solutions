// ==================================================
// Problem  :   Divisible by 8
// Run time :   0.072 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        char num[30];
        scanf("%s", num);

        int len = strlen(num);
        bool ans = false;

        if(len == 1) {
            if(num[0] == '8') ans = true;
        }
        else if(len == 2) {
            int n1 = (num[0]-'0') * 10 + (num[1]-'0');
            int n2 = (num[1]-'0') * 10 + (num[0]-'0');

            if(n1 % 8 == 0 || n2 % 8 == 0) ans = true;
        }
        else {
            for(int i = 0; i < len && !ans; ++i) {
                for(int j = 0; j < len && !ans; ++j) {
                    if(j == i) continue;

                    for(int k = 0; k < len && !ans; ++k) {
                        if(k == i || k == j) continue;

                        int n = (num[i]-'0') * 100 + (num[j]-'0') * 10 + (num[k]-'0');
                        if(n % 8 == 0) ans = true;
                    }
                }
            }
        }

        puts((ans)? "Yes" : "No");
    }

    return 0;
}
