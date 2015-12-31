#include <stdio.h>

int main()
{
    int tc, a, b;

    scanf("%d", &tc);

    while(tc--) {
        scanf("%d %d", &a, &b);

        if(b % a)
            printf("-1\n");
        else
            printf("%d %d\n", a, b);
    }

    return 0;
}
