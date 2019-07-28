// ==================================================
// Problem  :   1197C - Array Splitting
// Run time :   0.124 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
using namespace std;


typedef     pair<int, int>      ii;


vector<int> a_vals;
vector<ii> gaps;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, k;
    scanf("%d %d", &n, &k);

    int a;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        a_vals.push_back(a);
    }

    if(k == 1) {
        printf("%d\n", a_vals[n-1] - a_vals[0]);
        return 0;
    }

    for(int i = 1; i < n; ++i) {
        gaps.push_back(make_pair(a_vals[i] - a_vals[i-1], i));      // Each pair contains gap and index
    }

    sort(gaps.begin(), gaps.end(), greater<ii>());                  // Sort in descending order

    int min_cost = 0;

    sort(gaps.begin(), gaps.begin()+k-1, [](const ii &a, const ii &b) { return a.second < b.second; });     // Sort first (k-1) elements by the second element.

    for(int i = 0; i < k-1; ++i) {
        min_cost += a_vals[gaps[i].second - 1] - ((i == 0)? a_vals[0] : a_vals[gaps[i-1].second]);
    }

    min_cost += a_vals[n-1] - a_vals[gaps[k-2].second];             // Take the last sub-array

    printf("%d\n", min_cost);

    return 0;
}
