#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     long long           LL;
typedef     pair<int,int>       ii;
typedef     pair<ii,int>        iii;

const int MAXL = 50000+3, MAXK = 30+3;
const int BASE1 = 31, BASE2 = 37, MOD1 = 1e9+7, MOD2 = 1e9+9;

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

ii hashing(int data[], int sz)
{
    LL h1 = 0, h2 = 0;

    for(int i = 0; i < sz; ++i) {
        h1 = (h1 * BASE1 + data[i]) % MOD1;
        h2 = (h2 * BASE2 + data[i]) % MOD2;
    }

    return ii(h1, h2);
}

int get_ans(vector<iii> &V)
{
    V.push_back(iii(ii(-1, -1), -1));

    int sz = V.size(), prev = 0, mx = 0;

    for(int i = 1; i < sz; ++i) {
        if(V[prev].first != V[i].first) {
            mx = max(mx, V[i-1].second - V[prev].second);
            prev = i;
        }
    }

    return mx;
}

int main()
{
    //freopen("in", "r", stdin);

    int len, k, tc = 0;

    while(len = fastIn<int>(), k = fastIn<int>(), len || k) {
        int pool[MAXK][MAXL] = {{0}};

        for(int lane = 0; lane < k; ++lane) {
            int n = fastIn<int>(), mark;

            while(n--) {
                mark = fastIn<int>();
                ++pool[lane][mark+1];
            }
        }

        int maxx[len+3];

        for(int i = 1; i <= len; ++i) {
            int mx = 0;

            for(int lane = 0; lane < k; ++lane) {
                pool[lane][i] += pool[lane][i-1];   // Prefix sum.
                mx = max(mx, pool[lane][i]);        // max value in i-th column.
            }

            maxx[i] = mx;
        }

        maxx[0] = 0;
        int tuples[k+3];
        vector<iii> V;

        for(int i = 0; i <= len; ++i) {
            for(int lane = 0; lane < k; ++lane)
                tuples[lane] = maxx[i] - pool[lane][i];

            V.push_back(iii(hashing(tuples, k), i));
        }

        sort(V.begin(), V.end());

        printf("Case #%d: %d meter(s)\n", ++tc, get_ans(V));
    }

    return 0;
}
