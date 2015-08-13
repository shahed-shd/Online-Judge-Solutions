#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, hold_n;

    int r1, r2, r3, r4;

    while(cin >> n) {
        int zeros = 0;

        for(int i = 10; true; i *= 10) {
            r1 = r2 = r3 = r4 = 1;
            hold_n = n;

            while(hold_n--) {
                r2 = (r2 * 2) % i;
                r3 = (r3 * 3) % i;
                r4 = (r4 * 4) % i;
            }

            if( (r1+r2+r3+r4) % i == 0 ) ++zeros;
            else break;
        }

        cout << zeros << '\n';
    }

    return 0;
}
