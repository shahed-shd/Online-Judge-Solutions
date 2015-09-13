#include <cstdio>
using namespace std;

int main()
{
    short n, ara[55], tc = 0;

    while(scanf("%hd", &n), n != 0) {
        short avg, min_moves = 0, total_bricks = 0;

        for(short i = 0; i < n; ++i) {
            scanf("%hd", ara+i);
            total_bricks += ara[i];
        }

        avg = total_bricks / n;

        for(short i = 0; i < n; ++i) {
            if(ara[i] > avg) min_moves += ara[i] - avg;
        }

        printf("Set #%hd\nThe minimum number of moves is %hd.\n\n", ++tc, min_moves);
    }

    return 0;
}
