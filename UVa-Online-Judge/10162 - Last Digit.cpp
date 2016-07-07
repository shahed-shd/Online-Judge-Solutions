#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string n;

    while(cin >> n, n[0] != '0') {
        int n_mod_10 = n.back() - '0';

        int term[10] = {0};
        for(int i = 1; i <= n_mod_10; ++i) ++term[i];

        int n_by_10_mod_10 = 0;
        if(n.length() > 1) n_by_10_mod_10 = n[n.length()-2] - '0';

        for(int i = 1; i <= 9; ++i) term[i] = (term[i] + n_by_10_mod_10) % 10;

        int res = 0;

        res += term[1];
        res += (term[2] % 2 == 0)? 0 : 4;
        res += (term[3] % 2 == 0)? 0 : 7;
        res += (term[4] % 5) * 6;
        res += (term[5] % 2) * 5;
        res += (term[6] % 5) * 6;
        res += (term[7] % 2 == 0)? 0 : 3;
        res += (term[8] % 2 == 0)? 0 : 6;
        res += term[9] * 9;

        res %= 10;

        cout << res << '\n';
    }

    return 0;
}
