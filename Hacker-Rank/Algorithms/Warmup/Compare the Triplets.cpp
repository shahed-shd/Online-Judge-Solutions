#include <cstdio>
using namespace std;

int main()
{
    int a[3];

    for(int i = 0; i < 3; ++i) scanf("%d", a+i);

    int alice = 0, bob = 0, b;

    for(int i = 0; i < 3; ++i) {
        scanf("%d", &b);
        if(a[i] > b) ++alice;
        else if(a[i] < b) ++bob;
    }

    printf("%d %d\n", alice, bob);

    return 0;
}

