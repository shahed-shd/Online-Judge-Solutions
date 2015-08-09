#include <iostream>
using namespace std;

int main()
{
    long long int t, tc, a, b, c;
    bool flag;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> a >> b >> c;

        flag = 0;

        cout << "Case " << ++tc << ": ";

        if(c > a && c > b)
            flag = (a*a + b*b == c*c)? 1 : 0;

        if(b > a && b > c)
            flag = (a*a + c*c == b*b)? 1 : 0;

        if(a > b && a > c)
            flag = (c*c + b*b == a*a)? 1 : 0;

        if(flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
