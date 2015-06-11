#include <iostream>
using namespace std;

int main()
{
    int roubles_p, raise_p, roubles_d, dec_d;

    cin >> roubles_p >> raise_p >> roubles_d >> dec_d;

    while(roubles_p < roubles_d) {
        roubles_p += raise_p;

        if(roubles_p > roubles_d) {
            roubles_p = roubles_d;
            break;
        }

        roubles_d -= dec_d;
    }

    cout << roubles_p << '\n';

    return 0;
}
