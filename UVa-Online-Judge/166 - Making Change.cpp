// ==================================================
// Problem  :   166 - Making Change
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;


const int MAXA = 100 + 3;   // 100 = 500/5
const int INF = INT_MAX;
const int coins[] = {1, 2, 4, 10, 20, 40};  // 5c, 10c, 20c, 50c, $1 and $2
int available_change_coin_cnt[] = {INF, INF, INF, INF, INF, INF};


int get_coin_count(int amount, int available[])
{
    int tot_coin_cnt = 0;

    for(int i = 5; i >= 0; --i) {
        if(available[i]) {
            int cnt = min(amount / coins[i], available[i]);
            amount -= cnt * coins[i];
            tot_coin_cnt += cnt;
        }
    }

    return (amount == 0)? tot_coin_cnt : INF;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int a[6];

    while(scanf("%d %d %d %d %d %d", a, a+1, a+2, a+3, a+4, a+5), a[0] or a[1] or a[2] or a[3] or a[4] or a[5]) {
        double input_amount;
        scanf("%lf", &input_amount);

        int amount = input_amount * 20;     // input_amount * 100 / 5;

        int tot_available_amount = 0;
        for(int i = 0; i < 6; ++i)
            tot_available_amount += coins[i] * a[i];

        int min_coin_cnt = INF;

        for(int i = amount; i <= tot_available_amount; ++i) {
            int pay_coin_cnt = get_coin_count(i, a);
            int change_coin_cnt = get_coin_count(i - amount, available_change_coin_cnt);

            if(pay_coin_cnt != INF and change_coin_cnt != INF)
                min_coin_cnt = min(min_coin_cnt, pay_coin_cnt + change_coin_cnt);
        }

        printf("%3d\n", min_coin_cnt);
    }

    return 0;
}
