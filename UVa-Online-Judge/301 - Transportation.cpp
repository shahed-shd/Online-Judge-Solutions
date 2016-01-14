#include <cstdio>
#include <tuple>
#include <vector>
#include <climits>
using namespace std;

typedef     tuple<int,int,int>      iii;

vector<int> train;
vector<iii> orders;
int n, ord, mx_earn, earn;

void f(int x, int earn)
{
    if(x == ord) {
        mx_earn = max(mx_earn, earn);
        return;
    }

    // without accepting order[x].
    f(x+1, earn);

    // Now, with accepting order[x] if the train can load the passengers.
    int s, t, p;
    tie(s, t, p) = orders[x];

    for(int station = s; station < t; ++station) {
        if(train[station] + p > n) {
            for(int j = s; j < station; ++j) train[j] -= p;
            return;
        }

        train[station] += p;
    }

    f(x+1, earn + (t-s)*p);

    // Now, backtracking.
    for(int station = s; station < t; ++station)
        train[station] -= p;
}

int main()
{
    //freopen("in", "r", stdin);

    int b;

    while(scanf("%d %d %d", &n, &b, &ord), n || b || ord) {
        train.clear();
        orders.clear();

        train.assign(b+1, 0);

        int s, t, p;

        for(int i = 0; i < ord; ++i) {
            scanf("%d %d %d", &s, &t, &p);
            orders.push_back(iii(s, t, p));
        }

        mx_earn = INT_MIN;

        f(0, 0);

        printf("%d\n", mx_earn);
    }

    return 0;
}
