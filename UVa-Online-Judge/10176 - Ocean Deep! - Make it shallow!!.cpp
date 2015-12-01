#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    char ch;

    while(cin >> ch) {
        int res = ch - '0';

        while(cin >> ch, ch != '#')
            res = (res * 2 + ch - '0') % 131071;

        if(res) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
