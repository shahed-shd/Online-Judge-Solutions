// ==================================================
// Problem  :   888B - Buggy Robot
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;


const int MAXN = 100 + 3;


int main()
{
    //freopen("in.txt", "r", stdin);

    char str[MAXN];
    scanf("%*d %s", str);

    int u, d, l, r;
    u = d = l = r = 0;


    for(int i = 0; str[i]; ++i) {
        if(str[i] == 'U') ++u;
        else if(str[i] == 'D') ++d;
        else if(str[i] == 'L') ++l;
        else ++r;
    }

    printf("%d\n", 2 * (min(l, r) + min(u, d)));

    return 0;
}
