#include <stdio.h>

int main()
{
    int a, b, c, d;

    while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
        (b > c && d > a && c+d > a+b && c > 0 && d > 0 && !(a & 1))? puts("Valores aceitos") : puts("Valores nao aceitos");

    return 0;
}
