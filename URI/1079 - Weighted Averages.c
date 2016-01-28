#include <stdio.h>

int main()
{
    int tc;
    double a, b, c;

    scanf("%d", &tc);

    while(tc--) {
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("%.1lf\n", (a*2+b*3+c*5)/10);
    }

    return 0;
}
