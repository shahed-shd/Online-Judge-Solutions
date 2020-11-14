// ==================================================
// Problem  :   1445B - Elimination
// Run time :   0.031 sec
// Language :   C
// ==================================================

#include <stdio.h>

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", max(a + b, c + d));
    }
    
    return 0;
}
