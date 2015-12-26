#include <cstdio>
using namespace std;

int main()
{
    const double w1 = 3.5, w2 = 7.5;

    double a, b;
    scanf("%lf %lf", &a, &b);

    printf("MEDIA = %.5lf\n", (a*w1 + b*w2) / (w1+w2));

    return 0;
}
