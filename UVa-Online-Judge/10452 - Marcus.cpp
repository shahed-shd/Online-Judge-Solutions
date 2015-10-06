#include <cstdio>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int m, n;
        scanf("%d %d", &m, &n);

        char table[m][n];

        for(int i = 0; i < m; ++i)
            scanf("%s", &table[i][0]);

        // input complete.

        char sequence[8] = {'@', 'I', 'E', 'H', 'O', 'V', 'A', '#'};

        int r, c, seq;

        for(int i = 0; i < n; ++i) {
            if(table[m-1][i] == '@') {
                c = i;
                break;
            }
        }

        r = m-1;
        seq = 0;

        while(seq < 7) {
            if(c > 0 && table[r][c-1] == sequence[seq+1]) {
                printf("left");
                --c;
            }
            else if(c < n-1 && table[r][c+1] == sequence[seq+1]) {
                printf("right");
                ++c;
            }
            else {
                printf("forth");
                --r;
            }

            ++seq;

            if(seq != 7) putchar(' ');
        }

        putchar('\n');
    }

    return 0;
}
