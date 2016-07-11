#include <stdio.h>

int main()
{
    unsigned int a, b;

    while(~scanf("%u %u", &a, &b))
        printf("%u\n", a ^ b);

    return 0;
}
