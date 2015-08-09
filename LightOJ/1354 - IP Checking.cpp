#include <iostream>
#include <cstdio>
using namespace std;

bool is_equal(char *str, int num)
{
    int temp;

    temp = 0;
    for(int i = 7; i >= 0; i--) {
        if(str[i] == '1') {
            temp |= 1 << (7-i);
        }
    }

    if(temp == num) return 1;
    else return 0;
}


int main()
{
    int t, tc, a, b, c, d, y;
    char str[9];

    cin >> t;
    tc = 0;

    while(t--) {
        y = 0;

        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        scanf("%*c");
        scanf("%[^.]", str);
        scanf("%*c");

        if(is_equal(str, a)) y++;

        scanf("%[^.]", str);
        scanf("%*c");
        if(is_equal(str, b)) y++;

        scanf("%[^.]", str);
        scanf("%*c");
        if(is_equal(str, c)) y++;

        scanf("%[^\n]", str);
        scanf("%*c");
        if(is_equal(str, d)) y++;

        if(y == 4) printf("Case %d: Yes\n", ++tc);
        else printf("Case %d: No\n", ++tc);
    }

    return 0;
}
