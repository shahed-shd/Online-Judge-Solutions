// ==================================================
// Problem  :   Luck Balance
// Score    :   20 /20
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int li, ti, sum = 0;
    vector<int> V;

    while(n--) {
        scanf("%d %d", &li, &ti);

        if(ti) V.push_back(li);
        else sum += li;
    }

    sort(V.begin(), V.end(), greater<int>());

    int idx = 0, sz = V.size();

    while(idx < k and idx < sz) sum += V[idx++];

    while(idx < sz) sum -= V[idx++];

    printf("%d\n", sum);

    return 0;
}
