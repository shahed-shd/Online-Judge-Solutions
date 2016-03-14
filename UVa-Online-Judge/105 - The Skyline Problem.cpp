#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 10000+3;

int skyline[MAXN] = {0};
int frLine[MAXN] = {0};

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int l, h, r;

    int minL = INT_MAX;
    int maxR = INT_MIN;

    while(scanf("%d %d %d", &l, &h, &r) != EOF) {
        for(int i = l; i < r; ++i) {
            minL = min(minL, l);
            maxR = max(maxR, r);
            skyline[i] = max(skyline[i], h);
            frLine[i] = max(frLine[i], h);
        }
        skyline[r] = max(skyline[r], h);
    }

    int nowH = skyline[minL];

    for(int i = minL; i <= maxR; ) {
        if(i != minL) putchar(' ');
        printf("%d %d", i, nowH);

        while(frLine[i] == nowH && i <= maxR)
            ++i;

        nowH = frLine[i];
    }
    putchar('\n');

    return 0;
}
