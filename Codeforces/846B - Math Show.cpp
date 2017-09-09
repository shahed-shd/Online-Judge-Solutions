// ==================================================
// Problem  :   846B - Math Show
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXK = 45 + 3;

int main()
{
    int n, k, M;
    scanf("%d %d %d", &n, &k, &M);

    int t_arr[MAXK];
    for(int i = 0; i < k; ++i) scanf("%d", t_arr+i);
    sort(t_arr, t_arr+k);

    int t_sum = accumulate(t_arr, t_arr+k, 0);
    int ans = 0;

    for(int task_completed = 0; task_completed <= n; ++task_completed) {
        int minutes_spent = t_sum * task_completed;
        if(minutes_spent > M) break;

        int point = task_completed + task_completed * k;
        int minutes_rem = M - minutes_spent;

        for(int i = 0; i < k; ++i) {
            int now_take = t_arr[i] * (n - task_completed);

            if(now_take <= minutes_rem) {
                minutes_rem -= now_take;
                point += (n - task_completed);
            }
            else {
                point += minutes_rem / t_arr[i];
                break;
            }
        }

        ans = max(ans, point);
    }

    printf("%d\n", ans);

    return 0;
}
