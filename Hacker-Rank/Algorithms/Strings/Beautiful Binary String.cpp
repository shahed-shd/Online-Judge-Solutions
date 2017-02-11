// ==================================================
// Problem  :   Beautiful Binary String
// Score    :   20 /20
// Language :   C++
// ==================================================

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;

    for(int i = 1; i < n-1; ++i)
        if(s[i] == '1' && s[i-1] == '0' && s[i+1] =='0')
            ++cnt, i+=2;

    cout << cnt << '\n';

    return 0;
}
