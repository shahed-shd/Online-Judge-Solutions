// ==================================================
// Problem  :   1593C - Save More Mice
// Run time :   0.124 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        vector<int> coordinates;

        for(int i = 0; i < k; ++i) {
            int x;
            scanf("%d", &x);
            coordinates.push_back(x);
        }

        sort(coordinates.begin(), coordinates.end());
        
        int ans = 0;
        int catDistFromHole = n;

        for(auto rit = coordinates.rbegin(); rit != coordinates.rend(); ++rit) {
            int mouseDistFromHole = n - *rit;

            if(catDistFromHole > 1 && mouseDistFromHole < catDistFromHole) {
                ++ans;
                catDistFromHole -= mouseDistFromHole;
            } else {
                break;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
