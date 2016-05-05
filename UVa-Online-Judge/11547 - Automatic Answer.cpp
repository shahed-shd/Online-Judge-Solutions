#include <cstdio>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);

        int tmp = n * 315 + 36962;
        if(tmp < 0) tmp = - tmp;

        printf("%d\n", (tmp / 10) % 10);
    }

    return 0;
}
