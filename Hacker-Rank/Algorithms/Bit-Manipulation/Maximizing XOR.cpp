// ==================================================
// Problem  :   Maximizing XOR
// Score    :   30 /30
// Language :   C++14
// ==================================================


#include <cstdio>
using namespace std;


inline bool bitcheck(int n, int pos) { return (n & (1 << pos)); }


int main()
{
    int l, r;
    scanf("%d %d", &l, &r);

    int max_pos_where_bits_differ = 0;

    for(int i = 31; i >= 0; --i) {
        if(bitcheck(l, i) != bitcheck(r, i)) {
            max_pos_where_bits_differ = i;
            break;
        }
    }

    int ans = (1 << (max_pos_where_bits_differ + 1)) - 1;

    printf("%d\n", ans);

    return 0;
}
