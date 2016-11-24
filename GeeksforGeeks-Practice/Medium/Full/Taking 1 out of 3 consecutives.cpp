// ==================================================
// Problem  :   Taking 1 out of 3 consecutives
// Run time :   0.0.081 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, tmp;
        scanf("%d", &n);

        vector<int> V;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            V.push_back(tmp);
        }

        if(n <= 3) {
            printf("%d\n", *min_element(V.begin(), V.end()));
            continue;
        }

        for(int i = n-4; i >= 0; --i) {
            V[i] += min(V[i+1], min(V[i+2], V[i+3]));
        }

        printf("%d\n", min(V[0], min(V[1], V[2])));
    }

    return 0;
}
