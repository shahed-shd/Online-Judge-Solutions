#include <cstdio>
#include <cstdint>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        int8_t arr[n];
        int sum = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%hhd", arr+i);
            sum += arr[i];
        }

        double avg = 1.0 * sum / n;
        int cnt = 0;

        for(auto& x : arr)
            if(x > avg) ++cnt;

        printf("%.3lf%%\n", 100.0 * cnt / n);
    }

    return 0;
}
