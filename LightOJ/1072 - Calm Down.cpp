#include <iostream>
#include <cmath>
using namespace std;

#define PI acos(-1)

int main()
{
    int t, tc, n;
    double rad;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> rad >> n;

        cout.precision(10);
        cout << fixed;

        cout << "Case " << ++tc << ": " << (rad * sin(PI/n)) / (1 + sin(PI/n)) << '\n'; // sin(PI/n) = r / (R-r)
    }

    return 0;
}
