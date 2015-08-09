#include <iostream>
#include <cmath>
using namespace std;

#define PI acos(-1.0)

int main()
{
    long int t, tc, ox, oy, ax, ay, bx, by;
    double o_a, a_b, angle_aob, ans;

    cin >> t;
    tc = 0;

    cout.precision(8);
    fixed(cout);

    while(t--) {
        cin >> ox >> oy >> ax >> ay >> bx >> by;

        o_a = sqrt( (ox-ax)*(ox-ax) + (oy-ay)*(oy-ay) );
        a_b = sqrt( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) );

        angle_aob = acos( (o_a*o_a * 2 - a_b*a_b) / (2 * o_a * o_a) );   // OA=OB

        ans = 2 * PI * o_a * angle_aob / (2 * PI);

        cout << "Case " << ++tc << ": " << ans << '\n';
    }


    return 0;
}
