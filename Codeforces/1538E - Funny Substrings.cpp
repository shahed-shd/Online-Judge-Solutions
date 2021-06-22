// ==================================================
// Problem  :   1538E - Funny Substrings
// Run time :   0.062 sec
// Language :   C++17
// ==================================================


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


typedef     long long       LL;


class Word {
    public:
    string prefix, suffix;
    LL hahaCount;

    Word() = default;

    Word(const string& val) {
        this->prefix = this->constructPrefix(val);
        this->suffix = this->constructSuffix(val);
        this->hahaCount = countHaha(val);
    }

    Word(const Word& a, const Word& b) {
        this->prefix = a.prefix.length() < 3 ? constructPrefix(a.prefix + b.prefix) : a.prefix;
        this->suffix = b.suffix.length() < 3 ? constructSuffix(a.suffix + b.suffix) : b.suffix;
        this->hahaCount = a.hahaCount + b.hahaCount + countHaha(a.suffix + b.prefix);
    }

    string constructPrefix(const string& s) {
        return (s.length() <= 3) ? s : s.substr(0, 3);;
    }

    string constructSuffix(const string& s) {
        int len = s.length();
        return (len <= 3) ? s : s.substr(len - 3);;
    }

    int countHaha(const string& s) {
        const string haha = "haha";
        int cnt = 0;

        for (int i = 0; i + 3 < s.length(); ++i) {
            cnt += s.compare(i, 4, haha) == 0;
        }

        return cnt;
    }
};


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        unordered_map<string, Word> mp;
        string assignTo;

        while(n--) {
            string assignOp;
            cin >> assignTo >> assignOp;
            
            Word word;

            if (assignOp.front() == ':') {
                string val;
                cin >> val;
                word = Word(val);
            } else {
                string a, plus, b;
                cin >> a >> plus >> b;
                word = Word(mp[a], mp[b]);
            }

            mp[assignTo] = word;
        }

        cout << mp[assignTo].hahaCount << '\n';
    }

    return 0;
}
