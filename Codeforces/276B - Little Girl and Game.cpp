// ==================================================
// Problem  :   276B - Little Girl and Game
// Run time :   0.062 sec.
// Language :   C++11
// ==================================================

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string str;

    while(cin >> str) {
        int cnt[30] = {0};

        for(auto &ch : str) ++cnt[ch - 'a'];

        int oddTimesCharacterCount = 0;

        for(int i = 0; i < 26; ++i)
            if(cnt[i] & 1)
                ++oddTimesCharacterCount;

        puts((oddTimesCharacterCount == 0 || oddTimesCharacterCount & 1)? "First" : "Second");
    }

    return 0;
}
