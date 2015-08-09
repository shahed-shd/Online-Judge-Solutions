#include <iostream>
using namespace std;

int main()
{
    short t, a;

    cin >> t;

    while(t--) {
        cin >> a;
        cout << a/2 << ' ' << a - (a/2) << '\n';
    }

    return 0;
}
