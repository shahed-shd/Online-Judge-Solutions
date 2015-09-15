#include <iostream>
#include <map>
using namespace std;

class UFDS {
    map<string, pair<string, int> > mp;    // pair holds parent & setSize.
public:
    void makeSet(string name) {
        if(!mp.count(name)) mp[name] = make_pair(name, 1);
    }

    string findSet(string name) {
        if(mp[name].first == name) return name;
        return mp[name].first = findSet(mp[name].first);
    }

    void unionSet(string name1, string name2) {
        if(findSet(name1) != findSet(name2)) {
            string p1 = findSet(name1), p2 = findSet(name2);

            if(mp[p1].second > mp[p2].second) {
                mp[p2].first = p1;
                mp[p1].second += mp[p2].second;
            }
            else {
                mp[p1].first = p2;
                mp[p2].second += mp[p1].second;
            }
        }
    }

    int getSetSize(string name) {
        return mp[findSet(name)].second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int tc;

    cin >> tc;

    while(tc--) {
        int f;
        string name1, name2;
        UFDS uf;

        cin >> f;

        while(f--) {
            cin >> name1 >> name2;

            uf.makeSet(name1);
            uf.makeSet(name2);

            uf.unionSet(name1, name2);

            cout << uf.getSetSize(name1) << '\n';
        }
    }

    return 0;
}
