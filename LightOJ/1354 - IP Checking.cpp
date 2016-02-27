#include <cstdio>
#include <bitset>
using namespace std;

int  main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        unsigned int a[4];
        char aa[4][10];

        scanf("%u.%u.%u.%u\n%[^.].%[^.].%[^.].%s", a, a+1, a+2, a+3, aa[0], aa[1], aa[2], aa[3]);

        int cnt = 0;

        for(int i = 0; i < 4; ++i) {
            bitset<10> bits(string(aa[i]));

            if(bits.to_ulong() == a[i]) ++cnt;
        }

        printf("Case %d: %s\n", tc, (cnt == 4)? "Yes" : "No");
    }

    return 0;
}


// ------------------- Alternatively -------------------
/*

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

*/
