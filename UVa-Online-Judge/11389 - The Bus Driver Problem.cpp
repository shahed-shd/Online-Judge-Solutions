#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int n, d, r;

    while(scanf("%d %d %d", &n, &d, &r), n || d || r) {
        int morning[n], afternoon[n];

        for(auto& x : morning)
            scanf("%d", &x);

        for(auto& x : afternoon)
            scanf("%d", &x);

        sort(morning, morning+n);
        sort(afternoon, afternoon+n, greater<int>());

        long long int ans = 0;

        for(int i = 0; i < n; ++i)
            ans += (morning[i] + afternoon[i] > d)? (morning[i]+afternoon[i] - d) * r : 0;

        printf("%lld\n", ans);
    }

    return 0;
}
