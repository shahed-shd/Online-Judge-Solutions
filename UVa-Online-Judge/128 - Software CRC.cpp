#include <iostream>
#include <iomanip>
using namespace std;

#define G 34943

int main()
{
    string str;

    while(getline(cin, str), str[0] != '#') {
        if(str.empty()) {
            cout << "00 00\n";
            continue;
        }

        int len = str.length();

        // Horner's method.
        int sum = str[0];
        for(int i = 1; i < len; ++i) {
            sum = ((sum << 8) + str[i]);
            sum %= G;
        }

        // (sum << 16) might be greater than (2^31 - 1).
        sum = ((long long int)sum << 16) % G;

        int crc = G - sum;

        cout.unsetf(ios::dec);
        cout.setf(ios::hex | ios::uppercase);
        cout.fill('0');

        cout << setw(2) << (crc >> 8) << ' ' << setw(2) << (crc % 256) << '\n';
    }

    return 0;
}
