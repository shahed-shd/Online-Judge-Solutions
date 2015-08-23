#include <iostream>
using namespace std;

int main()
{
    string a, b;

    while(cin >> a >> b, a != "0" || b != "0") {
        int len = a.size();
        for(int i = 0; i < len/2; ++i) swap(a[i], a[len-i-1]);

        len = b.size();
        for(int i = 0; i < len/2; ++i) swap(b[i], b[len-i-1]);

        len = max(a.size(), b.size()) - a.size();
        while(len--) a.push_back('0');

        len = max(a.size(), b.size()) - b.size();
        while(len--) b.push_back('0');

        int carry = 0, cnt = 0;

        len = a.size();

        for(int i = 0; i < len; ++i) {
            carry = a[i] + b[i] - 96 + carry;
            carry /= 10;
            if(carry) ++cnt;
        }
        while(carry /= 10, carry > 0) ++cnt;

        if(cnt == 0) cout << "No carry operation.\n";
        else if(cnt == 1) cout << "1 carry operation.\n";
        else cout << cnt << " carry operations.\n";
    }

    return 0;
}
