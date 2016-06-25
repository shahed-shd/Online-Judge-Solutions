#include <cstdio>
using namespace std;

const int MAXN = 1e5+3, MAXQ = 50000+3;

int arr[MAXN+MAXQ];

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

class BIT {
    int tree[MAXN+MAXQ];
    int mx;

public:
    void init(int n, int q) {
        mx = n+q+3;
        for(int i = 0; i < mx; ++i) tree[i] = 0;
    }

    void update(int idx, int val) {
        while(idx < mx) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;

        while(idx >= 1) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }
} bit;

int call(int idx)
{
    int add = 0, now, prev = 0, addSum = 0;

    while(now = bit.query(idx), add = now - addSum, now != prev) {
        idx += add;
        addSum += add;
        prev = now;
    }

    bit.update(idx, 1);

    return arr[idx];
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>(), q = fastIn<int>();

        for(int i = 1; i <= n; ++i) arr[i] = fastIn<int>();

        bit.init(n, q);

        char cmd;
        int val, nowArmy = n, mxIdx = n;

        printf("Case %d:\n", tc);

        while(q--) {
            cmd = getchar();
            val = fastIn<int>();

            if(cmd == 'c') {
                if(val <= nowArmy) {
                    printf("%d\n", call(val));
                    --nowArmy;
                }
                else puts("none");
            }
            else {
                arr[++mxIdx] = val;
                ++nowArmy;
            }
        }
    }

    return 0;
}
