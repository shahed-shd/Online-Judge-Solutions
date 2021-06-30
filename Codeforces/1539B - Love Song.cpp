// ==================================================
// Problem  :   1539B - Love Song
// Run time :   0.092 sec
// Language :   C++17
// ==================================================


#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> cumSum;
    cumSum.push_back(0);

    for (const auto& x : s) {
        cumSum.push_back(x - 'a' + 1 + cumSum.back());
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << cumSum[r] - cumSum[l - 1] << '\n';
    }

    return 0;
}
