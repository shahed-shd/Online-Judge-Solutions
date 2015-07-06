#include <iostream>
#include <algorithm>
using namespace std;

string str[1001];

void calculate_factorials()
{
    str[0].push_back(1);

    for(int i = 1; i <= 1000; ++i) {
        int len, carry, res;
        len = str[i-1].length();

        carry = res = 0;
        for(int j = 0; j < len; ++j) {
            res = i * str[i-1].at(j);
            res += carry;

            str[i].push_back(res % 10);
            carry = res / 10;
        }
        while(carry) {
            str[i].push_back(carry % 10);
            carry /= 10;
        }
    }
}

int main()
{
    int n;

    calculate_factorials();

    while(cin >> n) {
        cout << n << "!\n";

        for(int i = str[n].length()-1; i >= 0; --i)
            cout << int(str[n].at(i));

        cout << '\n';
    }

    return 0;
}
