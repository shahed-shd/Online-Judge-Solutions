#include <iostream>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    unordered_map<string,pair<string,int> > table;
    string code;

    while(cin >> code, code != "000000") {
        string name;
        cin.ignore(1, ' ');
        getline(cin, name, '$');

        int price;
        cin >> price;

        table[code] = make_pair(name, price);
    }

    while(cin >> code, code != "#") {
        int minutes;
        cin >> minutes;

        bool isFound = false;
        pair<string, pair<string,int> > pr;

        for(auto& x : table) {
            if(code.find(x.first) == 0) {
                int subscriberCodeLength = code.length() - x.first.length();

                if((code[0] == '0' && code[1] == '0' && 4 <= subscriberCodeLength && subscriberCodeLength <= 10) ||
                    (code[0] == '0' && code[1] != '0' && 4 <= subscriberCodeLength && subscriberCodeLength <= 7)) {

                    isFound = true;
                    pr = x;
                    break;
                }
            }
        }

        cout.precision(2); fixed(cout);
        cout.unsetf(ios::right);
        cout.setf(ios::left);

        if(isFound) {
            cout << setw(16) << code
                << pr.second.first
                << setiosflags(ios::right) << setw(51 - 16 - pr.second.first.length()) << code.substr(pr.first.length())
                << setw(5) << minutes
                << setw(6) << pr.second.second/100.0
                << setw(7) << minutes * pr.second.second / 100.0 << '\n';
        }
        else if(code.front() != '0') {
            cout << setw(16) << code
                << "Local"
                << setiosflags(ios::right) << setw(51 - 16 - 5) << code
                << setw(5) << minutes
                << setw(6) << "0.00"
                << setw(7) << "0.00" << '\n';
        }
        else {
            cout << setw(16) << code
                << "Unknown"
                << setiosflags(ios::right) << setw(51 - 16 - 7 + 5) << minutes
                << setw(6+7) << "-1.00" << '\n';
        }
    }

    return 0;
}
