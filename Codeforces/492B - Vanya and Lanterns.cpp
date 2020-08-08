// ==================================================
// Problem  :   492B - Vanya and Lanterns
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, l;
    scanf("%d %d", &n, &l);

    set<int> lanternPoints;
    int point;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &point);
        lanternPoints.insert(point);
    }

    double d = *lanternPoints.begin();
    int prevPoint = 0;
    
    for(auto currPoint : lanternPoints) {
        d = max(d, (currPoint - prevPoint) / 2.0);
        prevPoint = currPoint;
    }

    d = max(d, double(l - prevPoint));

    printf("%.9f\n", d);

    return 0;
}
