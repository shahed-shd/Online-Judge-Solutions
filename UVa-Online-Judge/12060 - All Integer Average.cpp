#include <iostream>
#include <iomanip>
//#include <cstdio>
using namespace std;

typedef long long int LL;

LL gcd(LL m, LL n)
 {
    while (n != 0) {
	  LL t = m % n;
	  m = n;
	  n = t;
	}
    return m;
}

int length(LL n)
{
    int len;
    for(len = 0; n; ++len) n /= 10;
    return len;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n, num, tc = 0;

    while(cin >> n, n != 0) {
        LL sum = 0, a, b, c;

        for(int i = 0; i < n; ++i) {
            cin >> num;
            sum += num;
        }

        char sign = '+';

        if(sum < 0) {
            sign = '-';
            sum *= -1;
        }

        b = sum % n;
        sum -= b;

        a = sum / n;
        c = n;

        int g = gcd(b, c);
        b /= g;
        c /= g;

        cout << "Case " << ++tc << ":\n";

        if(b == 0) {
            if(sign == '-') cout << "- ";
            cout << a << '\n';
        }
        else {
            int len = 0;
            if(sign == '-') len += 2;
            len += length(a);
            len += length(c);

            cout.unsetf(ios::left);
            cout.setf(ios::right);
            cout << setw(len) << b << '\n';

            if(sign == '-') cout << "- ";
            if(a != 0) cout << a;
            cout << string(length(c), '-') << '\n';

            cout << setw(len) << c << '\n';
        }
    }

    return 0;
}
