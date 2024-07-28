// ==================================================
// Problem  :   Points On a Line
// Score    :   10 /10
// Language :   C++14
// ==================================================


#include <cstdio>
using namespace std;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    int x1, y1;
    scanf("%d %d", &x1, &y1);

    bool areAbscissasEqual = true, areOrdinatesEqual = true;


    while(--n) {
        int x, y;
        scanf("%d %d", &x, &y);

        areAbscissasEqual = areAbscissasEqual && x == x1;
        areOrdinatesEqual = areOrdinatesEqual && y == y1;
    }

    printf("%s\n", areAbscissasEqual || areOrdinatesEqual? "YES" : "NO");

    return 0;
}
