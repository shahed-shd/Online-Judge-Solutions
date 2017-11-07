// ==================================================
// Problem  :   887A - Div. 64
// Run time :   0.031 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    char num[100+3];

    scanf("%s", num);

    bool oneFound = false;
    int zeroCount = 0;

    for(int i = 0; num[i]; ++i) {
        if(num[i] == '1') oneFound = true;
        else if(oneFound) ++zeroCount;
    }

    puts((oneFound and zeroCount >= 6)? "yes" : "no");

    return 0;
}
