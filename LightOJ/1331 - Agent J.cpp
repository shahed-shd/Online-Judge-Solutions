#include <iostream>
#include <cmath>
using namespace std;

#define PI acos(-1)

int main()
{
    int t, tc;
    double r1, r2, r3, a, b, c, angle_a, angle_b, angle_c, area, ans;

    cin >> t;
    tc = 0;

    cout.precision(10);
    fixed(cout);

    while(t--) {
        cin >> r1 >> r2 >> r3;

        a = r2 + r3;
        b = r1 + r3;
        c = r1 + r2;

        angle_a = acos((b*b + c*c - a*a) / (2*b*c));
        angle_b = acos((a*a + c*c - b*b) / (2*a*c));
        angle_c = PI - angle_a - angle_b;

        area = 0.5 * a * b * sin(angle_c);

        ans = area;
        ans -= PI * r1 * r1 * angle_a / (2 * PI);
        ans -= PI * r2 * r2 * angle_b / (2 * PI);
        ans -= PI * r3 * r3 * angle_c / (2 * PI);

        cout << "Case " << ++tc << ": " << ans << '\n';
    }

    return 0;
}
