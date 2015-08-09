#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long int t, tc, r1, c1, r2, c2, diff_r, diff_c, diff;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> r1 >> c1 >> r2 >> c2;

        diff_r = abs(r1 - r2);
        diff_c = abs(c1 - c2);
        diff = abs(diff_r - diff_c);

        cout << "Case " << ++tc << ": ";

        if(diff_r == diff_c) cout << "1\n";
        else if(diff & 1) cout << "impossible\n";    //when diff is odd.
        else cout << "2\n";
    }

    return 0;
}
