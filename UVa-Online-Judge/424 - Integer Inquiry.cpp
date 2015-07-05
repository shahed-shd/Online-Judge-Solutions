#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str1, str2, str_res;

    while(getline(cin, str1), str1 != "0") {
        reverse(str1.begin(), str1.end());

        int len1, len2, mx_len, carry, res;

        len1 = str1.length();
        len2 = str2.length();
        mx_len = max(len1, len2);

        carry = res = 0;
        for(int i = 0; i < mx_len; ++i) {
            if(i < len1) res = str1[i] - '0';
            if(i < len2) res += str2[i];
            res += carry;

            str_res.push_back(res % 10);
            carry = res / 10;
            res = 0;
        }
        while(carry) {
            str_res.push_back(carry % 10);
            carry /= 10;
        }

        str2 = str_res;
        str_res.clear();
    }

    for(int i = str2.length()-1; i >= 0; --i) cout << int(str2[i]);

    cout << '\n';

    return 0;
}
