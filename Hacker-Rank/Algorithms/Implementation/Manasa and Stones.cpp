#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> V;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        V.clear();

        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        if(a < b) swap(a, b);

        for(int i = 0; i < n; ++i)
            V.push_back(a * i + b * (n-1-i));

        V.erase(unique(V.begin(), V.end()), V.end());

        printf("%d", V[0]);
        for(auto it = V.begin()+1; it != V.end(); ++it)
            printf(" %d", *it);
        putchar('\n');
    }

    return 0;
}
