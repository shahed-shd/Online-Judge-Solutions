// ==================================================
// Problem  :   Stepping Numbers
// Runtime  :   0.161 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1e6 + 3;

vector<int> steppingNumbers;

bool isStepping(int n)
{
    char num[10];
    sprintf(num, "%d", n);

    for(int i = 1; num[i]; ++i)
        if(abs(num[i-1] - num[i]) != 1)
            return false;

    return true;
}

void preprocess()
{
    for(int i = 0; i < MAXN; ++i)
        if(isStepping(i))
            steppingNumbers.push_back(i);
}

int main()
{
    int t;
    scanf("%d", &t);

    preprocess();

    while(t--) {
        int n, m;
        scanf("%d %d",  &n, &m);

        printf("%d\n", int(upper_bound(steppingNumbers.begin(), steppingNumbers.end(), m) - lower_bound(steppingNumbers.begin(), steppingNumbers.end(), n)));
    }

    return 0;
}
