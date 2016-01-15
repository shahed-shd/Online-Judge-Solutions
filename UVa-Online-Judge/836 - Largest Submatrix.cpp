#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;

const int N = 25;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        char str[N+5];
        scanf("%s\n", str);

        int len = strlen(str);

        bitset<N+1> inputMat[len];
        int mat[len][len];

        mat[0][0] = inputMat[0][0] = str[0] - '0';

        for(int i = 1; i < len; ++i) {
            inputMat[0][i] = str[i] - '0';
            mat[0][i] = inputMat[0][i] + mat[0][i-1];
        }

        char ch;

        for(int i = 1; i < len; ++i) {
            ch = getchar();
            inputMat[i][0] = ch - '0';
            mat[i][0] = inputMat[i][0] + mat[i-1][0];

            for(int j = 1; j < len; ++j) {
                ch = getchar();
                inputMat[i][j] = ch - '0';
                mat[i][j] = inputMat[i][j] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
            getchar();
        }

        // Input complete.

        int tmp, mx = 0;

        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                if(!inputMat[i][j]) continue;

                for(int x = i; x < len; ++x) {
                    for(int y = j; y < len; ++y) {
                        if(!inputMat[x][y]) continue;

                        tmp = mat[x][y];

                        if(i > 0) tmp -= mat[i-1][y];
                        if(j > 0) tmp -= mat[x][j-1];
                        if(i > 0 && j > 0) tmp += mat[i-1][j-1];

                        if(tmp > mx && (x-i+1)*(y-j+1) == tmp)
                            mx = tmp;
                    }
                }
            }
        }

        printf("%d\n", mx);

        if(t) putchar('\n');
    }

    return 0;
}
