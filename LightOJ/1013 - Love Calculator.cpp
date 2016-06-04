#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef     long long   LL;

const int MAXL = 30+3;

char str_a[MAXL], str_b[MAXL];
int len_a, len_b;
LL memo[MAXL][MAXL][MAXL+MAXL];

int ans1;
LL ans2;

int my_gets(char s[], int s_size)
{
    fgets(s, s_size, stdin);

    int s_len = strlen(s);
    if(s[s_len-1] == '\n') s[s_len-1] = '\0', --s_len;

    return s_len;
}

LL shortestLen(int idx_a, int idx_b, int num)
{
    if(idx_a == len_a || idx_b == len_b)
        return num + abs((len_a - idx_a) - (len_b - idx_b));

    LL& ret = memo[idx_a][idx_b][num];
    if(ret != -1) return ret;

    if(str_a[idx_a] == str_b[idx_b])
        ret = shortestLen(idx_a+1, idx_b+1, num+1);
    else
        ret = min(shortestLen(idx_a+1, idx_b, num+1), shortestLen(idx_a, idx_b+1, num+1));

    return ret;
}

LL num_unique_str(int idx_a, int idx_b, int num)
{
    if(idx_a == len_a || idx_b == len_b)
        return (num + abs((len_a - idx_a) - (len_b - idx_b)) == ans1);

    LL& ret = memo[idx_a][idx_b][num];
    if(ret != -1) return ret;

    if(str_a[idx_a] == str_b[idx_b])
        ret = num_unique_str(idx_a+1, idx_b+1, num+1);
    else
        ret = num_unique_str(idx_a+1, idx_b, num+1) + num_unique_str(idx_a, idx_b+1, num+1);

    return ret;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d\n", &t);

    for(int tc = 1; tc <= t; ++tc) {
        len_a = my_gets(str_a, sizeof(str_a));
        len_b = my_gets(str_b, sizeof(str_b));

        fill(&memo[0][0][0], &memo[MAXL][0][0], -1);

        ans1 = shortestLen(0, 0, 0);

        fill(&memo[0][0][0], &memo[MAXL][0][0], -1);

        ans2 = num_unique_str(0, 0, 0);

        printf("Case %d: %d %lld\n", tc, ans1, ans2);
    }

    return 0;
}
