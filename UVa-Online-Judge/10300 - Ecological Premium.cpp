#include <cstdio>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int f;
        scanf("%d", &f);

        long long sum = 0;
        int farmyard, equipment;

        while(f--) {
            scanf("%d %*d %d", &farmyard, &equipment);
            sum += farmyard * equipment;
        }

        printf("%lld\n", sum);
    }

    return 0;
}
