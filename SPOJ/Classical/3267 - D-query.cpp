// ==================================================
// Problem  :   3267 - D-query.cpp
// Run time :   0.260 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 30000 + 3;
const int MAXA = 1e6 + 3;
const int MAXQ = 200000 + 3;

struct query {
    int L, R, serial;
};

int arr[MAXN];
query qry[MAXQ];
int cnt[MAXA] = {0}, ans[MAXQ];
int  blockSize, currCnt;

template<class T>
inline T fastIn()
{
    register T a = 0;
    register char c = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

bool cmp(const query &x, const query &y)
{
    if(x.L/blockSize != y.L/blockSize)
        return x.L/blockSize < y.L/blockSize;
    return x.R < y.R;
}

inline void add(int val)
{
    if(++cnt[val] == 1) ++currCnt;
}

inline void rem(int val)
{
    if(--cnt[val] == 0) --currCnt;
}

void MOsAlgorithm(int n, int q)
{
    blockSize = sqrt(n);
    sort(qry, qry+q, cmp);

    int currL = 0, currR = 0;
    currCnt = 0;
    add(arr[0]);

    for(int i = 0; i < q; ++i) {
        int L = qry[i].L, R = qry[i].R, s = qry[i].serial;

        while(currL < L)
            rem(arr[currL++]);

        while(currL > L)
            add(arr[--currL]);

        while(currR < R)
            add(arr[++currR]);

        while(currR > R)
            rem(arr[currR--]);

        ans[s] = currCnt;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n = fastIn<int>();

    for(int i = 0; i < n; ++i)
        arr[i] = fastIn<int>();

    int q = fastIn<int>();

    for(int i = 0; i < q; ++i)
        qry[i] = {fastIn<int>()-1, fastIn<int>()-1, i};

    MOsAlgorithm(n, q);

    for(int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);

    return 0;
}
