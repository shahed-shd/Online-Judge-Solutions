// ==================================================
// Problem  :   Flipping bits
// Score    :   40 /40
// Language :   C++14
// ==================================================


#include <cstdio>
#include <cstdint>
using namespace std;


int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        uint32_t a;
        scanf("%u", &a);

        printf("%u\n", ~a);
    }

    return 0;
}
