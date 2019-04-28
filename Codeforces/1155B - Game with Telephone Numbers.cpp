// ==================================================
// Problem  :   1155B - Game with Telephone Numbers
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
using namespace std;


const int MAXN = 1e5 + 3;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    char s[MAXN];

    scanf("%d %s", &n, s);

    // Count the number of 8s which can be first digit of phone number after the game.
    int cnt8 = 0;

    for(int i = 0; i < n-10; ++i) {
        cnt8 += (s[i] == '8');
    }

    // Each player's turn count.
    int turn_cnt = (n - 11) / 2;

    if(cnt8 <= turn_cnt) {  // If Petya can remove the 8s, Vasya loses.
        puts("NO");
    }
    else {                  // Otherwise, Vasya has a winning strategy.
        puts("YES");
    }

    return 0;
}
