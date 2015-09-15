#include <iostream>
#include <map>
#include <vector>
using namespace std;

class UFDS {
    map<string, pair<string, short> > mp;    // pair holds parent & setSize.
public:
    void makeSet(string creature) {
        mp[creature] = make_pair(creature, 1);
    }

    string findSet(string creature) {
        if(mp[creature].first == creature)
            return mp[creature].first;

        mp[creature].first = findSet(mp[creature].first);
        return mp[creature].first;
    }

    void unionSet(string creature1, string creature2) {
        if(findSet(creature1) != findSet(creature2)) {
            string p1, p2;
            p1 = findSet(creature1);
            p2 = findSet(creature2);

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

    short getLargest() {
        short mx = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            if(mx < (it->second).second) mx = (it->second).second;
        }
        return mx;
    }
};

int main()
{
    short c, r;

    while(cin >> c >> r, c != 0 || r != 0) {
        UFDS uf;
        string creature;

        while(c--) {
            cin >> creature;
            uf.makeSet(creature);
        }

        string creature2;

        while(r--) {
            cin >> creature >> creature2;
            uf.unionSet(creature, creature2);
        }

        cout << uf.getLargest() << '\n';
    }

    return 0;
}
