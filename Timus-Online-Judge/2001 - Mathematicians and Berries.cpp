#include <cstdio>
using namespace std;

int main()
{
    int a1, b1, b2, a3;

    scanf("%d %d %*d %d %d %*d", &a1, &b1, &b2, &a3);

    printf("%d %d\n", a1-a3, b1-b2);

    return 0;
}
