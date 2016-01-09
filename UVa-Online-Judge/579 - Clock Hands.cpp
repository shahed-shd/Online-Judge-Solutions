#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int h, m;

    while(scanf("%d:%d", &h, &m), h || m) {
        double ans = fabs((30*h + m/2.0) - 6*m);

        if(ans > 180) ans = 360 - ans;

        printf("%.3lf\n", ans);
    }

    return 0;
}
