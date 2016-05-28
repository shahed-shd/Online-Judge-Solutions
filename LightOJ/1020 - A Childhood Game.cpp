#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        char name[10];
        scanf("%d %s", &n, name);

        printf("Case %d: ", tc);

        n %= 3;

        if(name[0] == 'A')
            (n == 0 || n == 2)? puts("Alice") : puts("Bob");
        else
            (n)? puts("Bob") : puts("Alice");
    }

    return 0;
}
