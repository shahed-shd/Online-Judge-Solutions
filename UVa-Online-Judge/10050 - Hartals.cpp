#include <cstdio>
#include <bitset>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n, p, h;
        scanf("%d %d", &n, &p);

        bitset<3650+10> hartals;

        while(p--) {
            scanf("%d", &h);

            for(int i = h; i <= n; i+=h)
                hartals[i] = true;
        }

        hartals[6] = hartals[7] = false;

        for(int i = 13; i <= n; i+=7)
            hartals[i] = hartals[i+1] = false;

        printf("%zu\n", hartals.count());
    }

    return 0;
}
