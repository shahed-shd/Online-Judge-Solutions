#include <iostream>
#include <cmath>
using namespace std;

#define PI (2 * acos(0.0))

int main() {
    int t, i;
    double r, blue_area;

    cin >> t;
    i = 0;

    while(t--) {
        cin >> r;

        blue_area = (4 * r * r) - (PI * r * r);
        cout.precision(2);
        cout << fixed;
        cout << "Case " << ++i << ": " << blue_area << '\n';
    }

    return 0;
}
