#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class UFDS {
    vector<int> par, rnk;
    int numSets;

public:
    UFDS(int n) {
        rnk.assign(n, 0);
        par.assign(n, 0);
        for(int i = 0; i < n; ++i) par[i] = i;
        numSets = n;
    }

    int findSet(int i) {
        return ((par[i] == i)? i : par[i] = findSet(par[i]));
    }

    void unionSet(int i, int j) {
        if(findSet(i) != findSet(j)) {
            int x = findSet(i), y = findSet(j);

            if(rnk[x] > rnk[y])
                par[y] = x;
            else {
                par[x] = y;
                if(rnk[x] == rnk[y]) ++rnk[y];
            }

            --numSets;
        }
    }

    int numDisjointSets() {
        return numSets;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int tc;
    string str;

    cin >> tc;

    while(tc--) {
        char largestNode;

        cin >> largestNode;
        cin.ignore(1, '\n');

        UFDS uf(largestNode - 'A' + 1);

        while(getline(cin, str), str != "") {
            uf.unionSet(str[0] - 'A', str[1] - 'A');
        }

        cout << uf.numDisjointSets() << '\n';

        if(tc) cout << '\n';
    }

    return 0;
}
