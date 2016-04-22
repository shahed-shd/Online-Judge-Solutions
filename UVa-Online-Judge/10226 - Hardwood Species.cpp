// Run time : 0.280 sec

#include <iostream>
#include <map>
using namespace std;

map<string, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);

    int tc;
    cin >> tc;

    cin.ignore(1, '\n');
    cin.ignore(1, '\n');

    while(tc--) {
        mp.clear();

        string str;
        int total = 0;

        while(getline(cin, str) && str.length()) {
            ++mp[str];
            ++total;
        }

        cout.precision(4); fixed(cout);

        for(auto it = mp.begin(); it != mp.end(); ++it)
            cout << it->first << ' ' << it->second * 1.0 / total * 100 << '\n';

        if(tc) cout << '\n';
    }

    return 0;
}
