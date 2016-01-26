#include <stdio.h>

int main()
{
    int n, res = 0;

    scanf("%d", &n);

    while(res+2 < 10000) {
        printf("%d\n", res+2);
        res += n;
    }

    return 0;
}

