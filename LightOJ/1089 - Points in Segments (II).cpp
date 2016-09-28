// ==================================================
// Problem  :   1089 - Points in Segments (II)
// Run time :   0.532 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef     pair<int, int>      ii;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

const int MAXN = 50000 + 3;

vector<ii> segments;
vector<int> values, queries;
map<int, int> id;

int treeSize, tree[MAXN*3 + 3];

void update(int idx, int val)
{
    while(idx < treeSize) {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

int query(int idx)
{
    int sum = 0;

    while(idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }

    return sum;
}


int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        segments.clear();
        values.clear();
        queries.clear();
        id.clear();

        int n = fastIn<int>(), q = fastIn<int>();
        int a, b;

        for(int i = 0; i < n; ++i) {
            a = fastIn<int>(), b = fastIn<int>();

            segments.push_back(ii(a, b));

            values.push_back(a);
            values.push_back(b);
        }

        for(int i = 0; i < q; ++i) {
            a = fastIn<int>();

            queries.push_back(a);
            values.push_back(a);
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int sz = values.size();

        for(int i = 0; i < sz; ++i)
            id[values[i]] = i;

        treeSize = values.size() + 3;
        fill(tree,  tree+treeSize, 0);

        for(int i = 0; i < n; ++i) {
            a = id[segments[i].first], b = id[segments[i].second];
            ++a, ++b;

            update(a, 1);
            update(b+1, -1);
        }

        printf("Case %d:\n", tc);

        for(int i = 0; i < q; ++i) {
            a = id[queries[i]];
            ++a;

            printf("%d\n", query(a));
        }
    }

    return 0;
}
