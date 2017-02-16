// ==================================================
// Problem  :   Two Characters
// Score    :   15 /15
// Language :   C++11
// ==================================================

#include <iostream>
#include <algorithm>
using namespace std;

int fn(char takeChars[], string &s)
{
    int sz = s.length();
    int prevIdx, currIdx, i;
    int ret = 0;

    for(i = 0; i < sz && !ret; ++i) {
        if(s[i] == takeChars[0])
            ++ret, prevIdx = 0, currIdx = 1;
        else if(s[i] == takeChars[1])
            ++ret, prevIdx = 1, currIdx = 0;
    }

    for( ; i < sz; ++i) {
        if(s[i] == takeChars[currIdx]) {
            ++ret;
            swap(currIdx, prevIdx);
        }
        else if(s[i] == takeChars[prevIdx]) {
            return -1;
        }
    }

    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    string uniqueChars = s;

    sort(uniqueChars.begin(), uniqueChars.end());
    uniqueChars.erase(unique(uniqueChars.begin(), uniqueChars.end()), uniqueChars.end());

    int sz = uniqueChars.length(), ans = 0;

    for(int i = 0; i < sz-1; ++i) {
        for(int j = i+1; j < sz; ++j) {
            char take[2] = {uniqueChars[i], uniqueChars[j]};
            ans = max(ans, fn(take, s));
        }
    }

    cout << ans << '\n';

    return 0;
}
