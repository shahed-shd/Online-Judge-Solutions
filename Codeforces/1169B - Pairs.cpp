// ==================================================
// Problem  :   1169B - Pairs
// Run time :   0.140 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


typedef     pair<int,int>   ii;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);

    vector<ii> pairs;
    int a, b;

    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        pairs.emplace_back(a, b);
    }

    vector<int> probable_x_values = {pairs[0].first, pairs[0].second};      // Any number in the 1st pair can be x
    bool ans = false;

    for(auto &x: probable_x_values) {
        vector<int> freq(n+1);      // Frequency count of values in pairs
        int pair_count_having_x = 0;

        for(auto &pr: pairs) {
            if(pr.first == x or pr.second == x) {
                ++pair_count_having_x;
            }
            else {
                ++freq[pr.first], ++freq[pr.second];
            }
        }

        if(*max_element(freq.begin(), freq.end()) == m - pair_count_having_x) {
            ans = true;
            break;
        }
    }

    printf("%s\n", (ans? "YES": "NO"));

    return 0;
}
