#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        unsigned n;
        scanf("%u", &n);

        bitset<32> b(n);

        string str(b.to_string());

        next_permutation(str.begin(), str.end());

        bitset<32> b2(str);

        printf("Case %d: %lu\n", tc, b2.to_ulong());
    }

    return 0;
}
