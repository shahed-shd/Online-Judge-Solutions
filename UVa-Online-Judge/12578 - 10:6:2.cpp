#include <cstdio>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        double L;
        scanf("%lf", &L);

        double redArea = PI * L * L / 25;

        printf("%.2lf %.2lf\n", redArea, 3*L*L/5 - redArea);
    }

    return 0;
}
