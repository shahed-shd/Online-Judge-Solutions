// ==================================================
// Problem  :   Satisfy the equation
// Run time :   0.082 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;

typedef     tuple<int,int,int,int>      iiii;

const int MAXN = 10 + 3;
const int MAXAI = 500 + 3;

struct p {
    int a, b;

    p() { a = b = -1; }

    bool any_match(int i, int j) {
        return (a == i || a == j || b == i || b == j);
    }
};

int n, arr[MAXN];
vector<p> V;

void solve()
{
    iiii res = make_tuple(n, n, n, n);

    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            int sum = arr[i] + arr[j];

            if(V[sum].a == -1) {
                V[sum].a = i, V[sum].b = j;
            }
            else if(!V[sum].any_match(i, j)) {
                res = min(res, make_tuple(V[sum].a, V[sum].b, i, j));
            }
        }
    }

    if(get<0>(res) != n)
        printf("%d %d %d %d\n", get<0>(res), get<1>(res), get<2>(res), get<3>(res));
    else
        puts("no pairs");
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        V.clear();
        V.resize(2*MAXAI);

        scanf("%d", &n);

        for(int i = 0; i < n; ++i) scanf("%d", arr+i);

        solve();
    }

    return 0;
}
