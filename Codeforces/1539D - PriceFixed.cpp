// ==================================================
// Problem  :   1539D - PriceFixed
// Run time :   0.093 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;


typedef     long long       LL;
typedef     pair<LL, LL>    PLL;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<PLL> pairs(n);

    for (auto& pr : pairs) {
        scanf("%lld %lld", &pr.first, &pr.second);
    }

    sort(pairs.begin(), pairs.end(), [](const PLL& lhs, const PLL& rhs) -> bool { return lhs.second < rhs.second; });

    LL totalItems = 0, totalCost = 0;
    int p1 = 0, p2 = n - 1;

    while(p1 <= p2) {
        LL minItemsForDiscount = pairs[p1].second;
        
        while (totalItems < minItemsForDiscount && p1 <= p2) {
            LL itemsNeeded = minItemsForDiscount - totalItems;
            LL currentItemsToBuy = (itemsNeeded <= pairs[p2].first) ? itemsNeeded : pairs[p2].first;

            pairs[p2].first -= currentItemsToBuy;
            totalItems += currentItemsToBuy;
            totalCost += currentItemsToBuy * 2;

            if (pairs[p2].first == 0) --p2;
        }

        if (p1 <= p2) {
            totalItems += pairs[p1].first;
            totalCost += pairs[p1].first;
            ++p1;
        }
    }

    printf("%lld\n", totalCost);

    return 0;
}
