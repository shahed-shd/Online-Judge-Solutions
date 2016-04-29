#include <cstdio>
using namespace std;

int gcd(int m, int n)
{
    while (n != 0) {
	  int t = m % n;
	  m = n;
	  n = t;
	}

    return m;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int sum = 0, numOfLoop = 0, x;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);

            if(x < 0) {
                ++numOfLoop;
                sum += (-x);
            }
            else sum += x;
        }

        printf("Case %d: ", tc);

        if(numOfLoop == n) {    // Impossible to get out of the maze.
            puts("inf");
            continue;
        }

        int numerator = sum, denominator = n - numOfLoop;

        int g = gcd(numerator, denominator);

        numerator /= g;
        denominator /= g;

        printf("%d/%d\n", numerator, denominator);
    }

    return 0;
}
