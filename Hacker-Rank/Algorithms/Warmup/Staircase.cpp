#include <cstdio>
using namespace std;

int main()
{
    int n;

    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; ++i) {
            for(int j = n-i; j > 0; --j) putchar(' ');

            for(int j = 1; j <= i; ++j) putchar('#');

            putchar('\n');
        }
    }

    return 0;
}
