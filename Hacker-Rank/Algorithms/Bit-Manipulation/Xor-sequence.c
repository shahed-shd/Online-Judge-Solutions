// ==================================================
// Problem  :   Xor-sequence
// Score    :   40 /40
// Language :   C
// ==================================================


#include <stdio.h>


typedef     long long       LL;


LL get_val(LL idx)
{
    int rem = idx % 4;

    if(rem == 0) return idx;
    if(rem == 1) return 1;
    if(rem == 2) return idx+1;
    return 0;   // if rem == 3
}


int main()
{
    int q;
    scanf("%d", &q);

    while(q--) {
        LL L, R;
        scanf("%lld %lld", &L, &R);

        LL a = L / 4 * 4;
        LL b = R / 4 * 4;

        LL res = (((b-a) / 4 + 1) & 1)? 2 : 0;

        for(LL i = a; i < L; ++i) {
            res ^= get_val(i);
        }

        for(LL i = b+3; i > R; --i) {
            res ^= get_val(i);
        }

        printf("%lld\n", res);
    }

    return 0;
}
