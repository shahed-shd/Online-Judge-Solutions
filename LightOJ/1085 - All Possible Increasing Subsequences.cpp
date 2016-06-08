#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef     pair<int,int>       ii;

const int MAXN = 1e5 + 3, MOD = 1000000007;

template<class T>
inline T fastIn()
{
    register char ch = 0;
    register T a = 0;
    bool neg = false;

    while(ch < 33) ch = getchar();

    if(ch == '-') neg = true;
    else a = ch - '0';

    while(ch = getchar(), ch > 33)
        a = a * 10 + (ch - '0');

    return (neg? -a : a);
}

class BIT {
    int tree[MAXN];
    int N;
public:
    BIT(int node) {
        N = node;
        for(int i = 0; i <= N; ++i) tree[i] = 0;
    }

    void update(int idx, int val) {
        while(idx <= N) {
            tree[idx] = (tree[idx] + val) % MOD;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum = (sum + tree[idx]) % MOD;
            idx -= idx & (-idx);
        }
        return sum;
    }
};

int process_input_with_ID(int input[], ii temp[], int n)
{
    sort(temp, temp+n);

    int maxID = 0;
    int num = temp[0].first;
    input[temp[0].second] = ++maxID;

    for(int i = 1; i < n; ++i) {
        if(temp[i].first == num)
            input[temp[i].second] = maxID;
        else
            num = temp[i].first, input[temp[i].second] = ++maxID;
    }

    return maxID;
}

int main()
{
    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        int input[n];
        ii temp[n];

        for(int i = 0; i < n; ++i) {
            input[i] = fastIn<int>();
            temp[i] = ii(input[i], i);
        }

        int maxID = process_input_with_ID(input, temp, n);

        BIT bt(maxID);

        for(int i = 0; i < n; ++i) {
            int tmp = bt.query(input[i]-1);
            bt.update(input[i], tmp+1);
        }

        printf("Case %d: %d\n", tc, bt.query(maxID));
    }

    return 0;
}
