#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n;
    bool newline = false;

    cin >> n;

    while(n--) {
        int m, i;
        char *digit1, *digit2, carry, res;

        cin >> m;

        digit1 = new char [m+2];
        digit2 = new char [m];

        for(i = m-1; i >= 0; --i)
            cin >> digit1[i] >> digit2[i];

        carry = 0;
        for(i = 0; i < m; ++i) {
            res = digit1[i] - '0' + digit2[i] - '0';
            res += carry;

            digit1[i] = (res % 10) + '0';
            carry = res / 10;
        }
        if(carry) digit1[i++] = carry + '0';
        digit1[i] = '\0';

        reverse(digit1, digit1+strlen(digit1));

        if(newline) cout << '\n';
        newline = true;

        cout << digit1 << '\n';

        delete [] digit1;
        delete [] digit2;
    }

    return 0;
}
