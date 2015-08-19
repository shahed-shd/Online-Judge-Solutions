#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int gcd(int m, int n)
{
    if(m < n) swap(m, n);

    int r;

    while(r = m % n, r != 0) m = n, n = r;

    return n;
}

int main()
{
    int j, k, tc = 0;
    string str;

    while(cin >> j, j != -1) {
        cin >> str;

        str = str.substr(2);

        int numerator = atoi(str.c_str());

        if(numerator == 0) {
            cout << "Case " << ++tc << ": 0/1\n";
            continue;
        }

        k = str.length() - j;

        int denominator;

        if(j == 0) {
            denominator = pow(10, k);
        }
        else {
            denominator = pow(10, k+j) - pow(10, k);

            while(j--) str.pop_back();  // str.pop_back() is in C++11

            numerator -= atoi(str.c_str());
        }

        int g = gcd(numerator, denominator);

        cout << "Case " << ++tc << ": " << numerator / g << '/' << denominator / g << '\n';
    }

    return 0;
}
