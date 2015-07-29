#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long int tc, n, ans;

    cin >> tc;

    while(tc--) {
        cin >> n;

        ans = (-1 + sqrt(1 + 8 * n)) / 2;

        cout << ans << '\n';
    }

    return 0;
}
