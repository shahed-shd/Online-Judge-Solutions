// ==================================================
// Problem   :   696A - Lorenzo Von Matterhorn
// Run time  :   0.046 sec.
// Language  :   C++11
// ==================================================

#include <cstdio>
#include <map>
using namespace std;

typedef     long long       LL;
typedef     pair<LL,LL>     iLiL;

map<iLiL, LL> cost;

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

int ilog2(LL n)
{
    int i = -1;

    if(n & 0xffffffff00000000) { i += 32; n >>= 32; }

    if(n & 0xffff0000) { i += 16; n >>= 16; }

    if(n & 0xff00) { i += 8; n >>= 8; }

    if(n & 0xf0) { i += 4; n >>= 4; }

    if(n & 0b1100) { i += 2; n >>= 2; }

    if(n & 0b10) { i += 1; n >>= 1; }

    if(n) ++i;

    return i;
}

void update(LL u, LL v, LL w)
{
    if(ilog2(u) < ilog2(v)) swap(u, v);

    int vLevel = ilog2(v);

    while(ilog2(u) > vLevel) {
        cost[iLiL(u >> 1, u)] += w;
        u >>= 1;
    }

    while(u != v) {
        cost[iLiL(u >> 1, u)] += w;
        cost[iLiL(v >> 1, v)] += w;
        u >>= 1;
        v >>= 1;
    }
}

LL query(LL u, LL v)
{
    if(ilog2(u) < ilog2(v)) swap(u, v);

    int vLevel = ilog2(v);
    LL res = 0;

    while(ilog2(u) > vLevel) {
        res += cost[iLiL(u >> 1, u)];
        u >>= 1;
    }

    while(u != v) {
        res += cost[iLiL(u >> 1, u)];
        res += cost[iLiL(v >> 1, v)];
        u >>= 1;
        v >>= 1;
    }

    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int q = fastIn<int>();

    int type;
    LL u, v, w;

    while(q--) {
        type = fastIn<int>();

        if(type == 1) {
            u = fastIn<LL>(), v = fastIn<LL>(), w = fastIn<LL>();
            update(u, v, w);
        }
        else {
            u = fastIn<LL>(), v = fastIn<LL>();
            printf("%I64d\n", query(u, v));
        }
    }

    return 0;
}
