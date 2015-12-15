#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        string cmd, url;
        vector<string> v;

        v.push_back("http://www.lightoj.com/");
        int pos = 0;

        cout << "Case " << tc << ":\n";

        while(cin >> cmd, cmd != "QUIT") {
            if(cmd == "VISIT") {
                cin >> url;
                v.resize(pos+1);

                v.push_back(url);
                cout << v[++pos] << '\n';
            }
            else if(cmd == "BACK") {
                if(pos-1 < 0) cout << "Ignored\n";
                else cout << v[--pos] << '\n';
            }
            else if(cmd == "FORWARD") {
                if(pos+1 >= int(v.size()))  cout << "Ignored\n";
                else cout << v[++pos] << '\n';
            }
        }
    }

    return 0;
}
