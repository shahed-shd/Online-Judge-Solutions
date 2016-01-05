#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string s, t;

    while(cin >> s >> t) {
        int len_s = s.length(), len_t = t.length();
        int idx = 0, cnt = 0;

        for(int i = 0; i < len_s; ++i) {
            for( ; idx < len_t; ++idx) {
                if(s[i] == t[idx]) {
                    ++cnt;
                    ++idx;
                    break;
                }
            }

            if(idx == len_t) break;
        }

        if(cnt == len_s) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
