#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t, tc, ax, ay, bx, by, cx, cy, dx, dy, diff_x, diff_y;
    double a_b, b_c, c_a, s, area;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> ax >> ay >> bx >> by >> cx >> cy;

        diff_x = cx - bx;
        diff_y = cy - by;

        dx = ax + diff_x;
        dy = ay + diff_y;

        a_b = sqrt( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) );
        b_c = sqrt( (bx-cx)*(bx-cx) + (by-cy)*(by-cy) );
        c_a = sqrt( (ax-cx)*(ax-cx) + (ay-cy)*(ay-cy) );
        s = (a_b + b_c + c_a) / 2;

        area = 2 * sqrt(s * (s - a_b) * (s - b_c) * (s - c_a));

        cout.precision(0);
        fixed(cout);

        cout << "Case " << ++tc << ": " << dx << ' ' << dy << ' ' << area << '\n';
    }

    return 0;
}

//***************************************************************************
// Alternative solution. by getting a rule to calculate the distance from a point to a line having two points,
// rule link: http://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t, tc, ax, ay, bx, by, cx, cy, dx, dy, diff_x, diff_y;
    //double a_b, b_c, c_a, s, area;
    double a_b, area;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> ax >> ay >> bx >> by >> cx >> cy;

        diff_x = cx - bx;
        diff_y = cy - by;

        dx = ax + diff_x;
        dy = ay + diff_y;

        a_b = sqrt( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) );
        //b_c = sqrt( (bx-cx)*(bx-cx) + (by-cy)*(by-cy) );
        //c_a = sqrt( (ax-cx)*(ax-cx) + (ay-cy)*(ay-cy) );
        //s = (a_b + b_c + c_a) / 2;

        //area = 2 * sqrt(s * (s - a_b) * (s - b_c) * (s - c_a));

        area = a_b * ( abs((by - ay) * dx - (bx - ax) * dy + bx*ay - by*ax ) / sqrt( (by - ay)*(by - ay) + (bx - ax)*(bx - ax) ));

        cout.precision(0);
        fixed(cout);

        cout << "Case " << ++tc << ": " << dx << ' ' << dy << ' ' << area << '\n';
    }

    return 0;
}
*/
