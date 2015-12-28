#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<vector<int> > table;
vector<int> arr;

void formTable(int n)   // forming the sparse table.
{
    for(int j = 1; (1 << j) < n; ++j) {
        for(int i = 0; i < n; ++i) {
            if(int(table[i].size()) >= j && int(table[i-(1<<(j-1))].size()) >= j)
                table[i].push_back(min(table[i][j-1], table[i - (1 << (j-1))][j-1]));
        }
    }
}

int findMin(int a, int b)   // always a <= b, according to the problem description.
{
    if(a == b) return arr[a];

    int mini = INT_MAX;

    for(int i = log2(b-a); i >= 0; --i) {
        if(b - (1<<i) >= a) {
            mini = min(mini, table[b][i]);
            b -= (1 << i);
        }
    }

    return mini;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        table.clear();
        arr.clear();

        int n, q;
        scanf("%d %d", &n, &q);

        table.resize(n);
        arr.resize(n);

        scanf("%d", &arr[0]);

        for(int i = 1; i < n; ++i) {
            scanf("%d", &arr[i]);
            table[i].push_back(min(arr[i], arr[i-1]));
        }

        formTable(n);

        printf("Case %d:\n", tc);

        int a, b;
        while(q--) {
            scanf("%d %d", &a, &b);
            printf("%d\n", findMin(--a, --b));
        }
    }

    return 0;
}
