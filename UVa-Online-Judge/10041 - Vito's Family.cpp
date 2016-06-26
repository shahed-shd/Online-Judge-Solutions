#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

const int MAXR = 500+3;

int arr[MAXR];

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int r;
        scanf("%d", &r);

        int distSum[MAXR] = {0};

        for(int i = 0; i < r; ++i) {
            scanf("%d", arr+i);

            for(int j = 0; j < i; ++j) {
                int d = abs(arr[i] - arr[j]);
                distSum[i] += d;
                distSum[j] += d;
            }
        }

        int minDist = INT_MAX;

        for(int i = 0; i < r; ++i)
            minDist = min(minDist, distSum[i]);

        printf("%d\n", minDist);
    }

    return 0;
}
