// Run time: 0.304 sec.

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef     unsigned long long      ULL;

const int MAXL = 50000+3, MAXK = 30+3;

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

ULL fnv_hashing(int data[], int k)
{
    ULL h = 2166136261U;

    for(int i = 1; i <= k; ++i)
        h = (h * 16777619U) ^ data[i];

    return h;
}

int get_ans(vector<pair<ULL, int> > &V)
{
    int s = 0, t = V.size(), prev = 0;
    int mx = 0;

    while(++s < t) {
        if(V[prev].first != V[s].first) {
            mx = max(mx, V[s-1].second - V[prev].second);
            prev = s;
        }
    }

    if(V[prev].first == V.back().first)
        mx = max(mx, V.back().second - V[prev].second);

    return mx;
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int len = fastIn<int>(), k = fastIn<int>();

        int pool[MAXK][MAXL] = {{0}};

        for(int lane = 1; lane <= k; ++lane) {
            int n = fastIn<int>(), mark;

            while(n--) {
                mark = fastIn<int>();
                ++pool[lane][mark+1];
            }
        }

        int mxx[len+1];
        vector<pair<ULL, int> > V;

        for(int i = 1; i <= len; ++i) {
            int mx = 0;

            for(int lane = 1; lane <= k; ++lane) {
                pool[lane][i] += pool[lane][i-1];   // Prefix sum.
                mx = max(mx, pool[lane][i]);        // max value in i-th column.
            }

            mxx[i] = mx;
        }

        mxx[0] = 0;
        int tuples[k+1];

        for(int i = 0; i <= len; ++i) {
            for(int lane = 1; lane <= k; ++lane)
                tuples[lane] = mxx[i] - pool[lane][i];

            V.push_back(make_pair(fnv_hashing(tuples, k), i));
        }

        sort(V.begin(), V.end());

        printf("Case %d: %d meter(s)\n", tc, get_ans(V));
    }

    return 0;
}
