// ==================================================
// Problem  :   Game of Thrones - I
// Score    :   30 /30
// Language :   C++11
// ==================================================

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bitset<30> b;

    for(auto &x : s) b.flip(x-'a');

    cout << ((b.count() <= 1)? "YES\n" : "NO\n");

    return 0;
}
