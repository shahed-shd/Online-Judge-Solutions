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


// ---------------- Alternatively ----------------
/*

#include <iostream>
#include <stack>
using namespace std;

int  main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tc = 1; tc <= t; ++tc) {
        stack<string> st_b, st_f;

        string cmd, currPage("http://www.lightoj.com/");

        cout << "Case " << tc << ":\n";

        while(cin >> cmd, cmd != "QUIT") {
            if(cmd == "BACK") {
                if(st_b.empty()) cout << "Ignored\n";
                else {
                    st_f.push(currPage);
                    currPage = st_b.top();
                    st_b.pop();
                    cout << currPage << '\n';
                }
            }
            else if(cmd == "FORWARD") {
                if(st_f.empty()) cout << "Ignored\n";
                else {
                    st_b.push(currPage);
                    currPage = st_f.top();
                    st_f.pop();
                    cout << currPage << '\n';
                }
            }
            else if(cmd == "VISIT") {
                stack<string> st_empty;
                swap(st_f, st_empty);

                st_b.push(currPage);

                cin >> currPage;
                cout << currPage << '\n';
            }
        }
    }

    return 0;
}

*/
