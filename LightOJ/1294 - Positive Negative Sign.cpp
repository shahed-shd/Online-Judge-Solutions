#include <iostream>
using namespace std;

int main()
{
    long int t, tc, n, m, sum;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> n >> m;

        sum = m * m; //sum up to 2m

        sum = sum * (n / (2 * m));

        cout << "Case " << ++tc << ": "<< sum << '\n';
    }

    return 0;
}
