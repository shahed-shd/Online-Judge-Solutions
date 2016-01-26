#include <stdio.h>
#include <limits.h>

int main()
{
    int i, n, mx = INT_MIN, pos;

    for(i = 1; i <= 100; i++) {
        scanf("%d", &n);

        if(n > mx) {
            mx = n;
            pos = i;
        }
    }

    printf("%d\n%d\n", mx, pos);

    return 0;
}

