#include <iostream>
//#include <cstdio>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    cin.unsetf(ios::skipws);
    char ch;
    int cnt = 0;

    while(cin >> ch) {
        if(ch == '!' || ch == '\n') cout << '\n';

        else if('0' <= ch && ch <= '9') cnt += (ch - '0');

        else {
            if(ch == 'b') ch = ' ';
            cout << string(cnt, ch);
            cnt = 0;
        }
    }

    return 0;
}
