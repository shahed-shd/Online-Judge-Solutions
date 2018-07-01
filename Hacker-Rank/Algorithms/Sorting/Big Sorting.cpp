// ==================================================
// Problem  :   Big Sorting
// Score    :   20 /20
// Language :   C++14
// ==================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<string> V;


bool cmp(const string &a, const string &b)
{
    if(a.length() == b.length()) {
        return a < b;
    }

    return a.length() < b.length();
}


int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    V.resize(n);

    for(auto &x : V) {
        cin >> x;
    }

    sort(V.begin(), V.end(), cmp);

    for(auto &x : V) {
        cout << x << '\n';
    }

    return 0;
}
