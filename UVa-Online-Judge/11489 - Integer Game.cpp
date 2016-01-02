#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        string str;
        cin >> str;

        int cnt[10] = {0};

        for(auto& x : str)
            ++cnt[x - '0'];

        int sum = 0;
        for(int i = 1; i <= 9; ++i)
            sum += cnt[i] * i;

        int moves = 2;  // initialized with an even value.

        if(sum % 3 == 0)
            moves = cnt[3] + cnt[6] + cnt[9];
        else {
            for(int i = 1; i < 9; ++i) {
                if(i%3 && !((sum-i)%3) && cnt[i]) {
                    moves = cnt[3] + cnt[6] + cnt[9] + 1;
                    break;
                }
            }
        }

        cout << "Case " << tc << ": ";

        if(moves & 1)
            cout << "S\n";
        else
            cout << "T\n";
    }
    
    return 0;
}
