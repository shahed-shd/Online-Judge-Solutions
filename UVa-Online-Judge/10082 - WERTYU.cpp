// ==================================================
// Problem  :   10082 - WERTYU
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string keyboard("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
    char decode[130];
    int len = keyboard.length();

    for(int i = 1; i < len; ++i)
        decode[int(keyboard[i])] = keyboard[i-1];

    decode[' '] = ' ';

    string s;

    while(getline(cin, s)) {
        for(auto &ch : s)
            ch = decode[int(ch)];

        cout << s << '\n';
    }

    return 0;
}
