#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n][n];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);

            if(i > 0) arr[i][j] += arr[i-1][j];
            if(j > 0) arr[i][j] += arr[i][j-1];
            if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
        }
    }

    int temp, ans = arr[0][0];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int x = i; x < n; ++x) {
                for(int y = j; y < n; ++y) {
                    temp = arr[x][y];

                    if(i > 0) temp -= arr[i-1][y];
                    if(j > 0) temp -= arr[x][j-1];
                    if(i > 0 && j > 0) temp += arr[i-1][j-1];

                    if(temp > ans) ans = temp;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
