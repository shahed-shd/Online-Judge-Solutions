#include <cstdio>
using namespace std;

int f(int n)
{
    int sum = 0;

    while(n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int g(int n)
{
    int ret;

    while(ret = f(n), ret > 9)
        n = ret;

    return ret;
}

int main()
{
    int n;

    while(scanf("%d", &n), n)
        printf("%d\n", g(n));

    return 0;
}
