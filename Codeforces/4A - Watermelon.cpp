#include <cstdio>
using namespace std;

int main()
{
    int w;

    while(scanf("%d", &w) != EOF) {
        if(w == 2) puts("NO");
        else (w & 1)? puts("NO") : puts("YES");
    }

    return 0;
}
