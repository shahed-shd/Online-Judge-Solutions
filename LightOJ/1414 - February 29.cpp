#include <cstdio>
using namespace std;

bool is_leapyear(long int y);

int main()
{
    int t, tc, d2;
    long int y1, y2, ans;
    char str[11], m1_initial, m1_2nd_ch, m2_initial, m2_2nd_ch;

    scanf("%d", &t);
    scanf("%*c");

    tc = 0;

    while(t--) {
        scanf("%s %*d %*c %ld", str, &y1);
        scanf("%*c");

        m1_initial = str[0];
        m1_2nd_ch = str[1];

        scanf("%s %d %*c %ld", str, &d2, &y2);
        scanf("%*c");

        m2_initial = str[0];
        m2_2nd_ch = str[1];

        // Input complete...... Now, processing.......

        ans = (y2/4 - y2/100 + y2/400) - (y1/4 - y1/100 + y1/400);

        if(is_leapyear(y1)) {
            if(m1_initial == 'F' || (m1_initial == 'J' && m1_2nd_ch == 'a') )
                ans++;
        }

        if(is_leapyear(y2)) {
            if((m2_initial == 'F' && d2 < 29) || (m2_initial == 'J' && m2_2nd_ch == 'a') )
                ans--;
        }

        printf("Case %d: %ld\n", ++tc, ans);
    }

    return 0;
}

bool is_leapyear(long int y)
{
    if( !(y % 100) ) {
        if( !(y % 400) )
            return 1;
        else
            return 0;
    }
    else if( !(y % 4))
        return 1;
    else
        return 0;
}
