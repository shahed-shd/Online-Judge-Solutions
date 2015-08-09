#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t, tc, me, lift, ans;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> me >> lift;

        ans = abs(lift - me) * 4 + me * 4 + 19; //lift comes + lift goes to ground floor + 3 + 3 + 3 + 5 + 5;

        cout << "Case " << ++tc << ": " << ans << '\n';
    }

    return 0;
}
