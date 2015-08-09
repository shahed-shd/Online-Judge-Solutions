#include <iostream>
using namespace std;

int main()
{
    short i, t, a, b;
    cin >> t;
    i = 1;
    while(t--) {
        cin >> a >> b;
        cout << "Case " << i++ << ": " << a+b << '\n';
    }

    return 0;
}
