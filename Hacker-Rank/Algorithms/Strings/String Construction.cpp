// ==================================================
// Problem  :   String Construction
// Score    :   25 /25
// Language :   C++14
// ==================================================

#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;

        bool letter_present[26 + 3] = {0};

        for(auto &x : s)
            letter_present[x - 'a'] = true;

        int res = 0;

        for(auto &x : letter_present)
            res += x;

        cout << res << '\n';
    }

    return 0;
}
