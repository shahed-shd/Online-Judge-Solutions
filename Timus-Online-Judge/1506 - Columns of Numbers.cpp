#include <cstdio>
using namespace std;

int main()
{
    int n, k, *num, i, j, rows;

    scanf("%d %d", &n, &k);

    num = new int [n];

    for(i = 0; i < n; ++i) scanf("%d", &num[i]);

    rows = (n % k)? n/k + 1 : n / k;

    for(j = 0; j < rows; j++) {
        for(i = j; i < n; i += rows) {
            printf("%4d", num[i]);
        }
        printf("\n");
    }

	delete [] num;

    return 0;
}
