// ==================================================
// Problem  :   1169A - Circle Metro
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
using namespace std;


int n;


int next_of_first_route(int from)
{
    int to = from + 1;
    if(to > n) to = 1;
    return to;
}


int next_of_second_route(int from)
{
    int to = from - 1;
    if(to < 1) to = n;
    return to;
}


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int a, x, b, y;
    scanf("%d %d %d %d %d", &n, &a, &x, &b, &y);

    int nxt1 = a, nxt2 = b;
    bool ans = false;

    do {
        nxt1 = next_of_first_route(nxt1);
        nxt2 = next_of_second_route(nxt2);

        if(nxt1 == nxt2) {
            ans = true;
            break;
        }
    } while(nxt1 != x and nxt2 != y);

    printf("%s\n", (ans? "YES": "NO"));

    return 0;
}
