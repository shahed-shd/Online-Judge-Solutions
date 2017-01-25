// ==================================================
// Problem  :   1211 - Intersection of Cubes
// Run time :   0.004 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int xyz[6], XYZ[6] = {1, 1, 1, 1000, 1000, 1000};

        while(n--) {
            for(int i = 0; i < 6; ++i) scanf("%d", xyz+i);

            for(int i = 0; i < 3; ++i) XYZ[i] = max(XYZ[i], xyz[i]);
            for(int i = 3; i < 6; ++i) XYZ[i] = min(XYZ[i], xyz[i]);
        }

        int d[3], volume;
        for(int i = 0; i < 3; ++i) d[i] = XYZ[i+3] - XYZ[i];

        if(d[0] > 0 && d[1] > 0 && d[2] > 0) volume = d[0] * d[1] * d[2];
        else volume = 0;

        printf("Case %d: %d\n", tc, volume);
    }

    return 0;
}
