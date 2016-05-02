#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double K = 2/sqrt(3.0);

int calc_skew(double a, double b)
{
    int col = int(b);
    int row = 1 + K*(a-1);

    return row * col - ((b - int(b) < 0.5)? row/2 : 0);
}

int main()
{
    double a, b;

    while(scanf("%lf %lf", &a, &b) != EOF) {
        int grid = int(a) * int(b);

        int skew = max(calc_skew(a, b), calc_skew(b, a));

        if(grid >= skew) printf("%d grid\n", grid);
        else printf("%d skew\n", skew);
    }

    return 0;
}
