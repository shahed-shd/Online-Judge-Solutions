// ==================================================
// Problem  :   Sparse Arrays
// Score    :   25 /25
// Language :   C++14
// ==================================================

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;

    unordered_map<string, int> mp;
    string s;

    while(n--) {
        cin >> s;
        ++mp[s];
    }

    int q;
    cin >> q;

    unordered_map<string, int>::iterator it;

    while(q--) {
        cin >> s;
        it = mp.find(s);
        cout << ((it != mp.end())? it->second : 0) << '\n';
    }

    return 0;
}
