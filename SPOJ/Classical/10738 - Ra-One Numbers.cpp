#include <cstdio>
#include <bitset>
using namespace std;

bitset<50> isMemo[12][50];
int memo[12][50][50];

int fn(int digPos, int sumOdd, int sumEven)
{
    if(digPos == 0)
        return (sumEven - sumOdd == 1);

    if(isMemo[digPos][sumOdd][sumEven]) return memo[digPos][sumOdd][sumEven];

    bool flag = digPos & 1;
    int& ret = memo[digPos][sumOdd][sumEven];
    ret = 0;

    if(flag) {      // That is, now working in odd position.
        for(int i = 0; i <= 9; ++i)
            ret += fn(digPos-1, sumOdd+i, sumEven);
    }
    else {          // That is, now working in even position.
        for(int i = 0; i <= 9; ++i)
            ret += fn(digPos-1, sumOdd, sumEven+i);
    }

    isMemo[digPos][sumOdd][sumEven] = true;;
    return ret;
}

int lucifer(int n)
{
    ++n;

    char str[15];
    int len = sprintf(str, "%d", n);

    int sumOdd = 0, sumEven = 0, cnt = 0;

    for(int i = 0; str[i]; ++i) {
        bool flag = len & 1;
        int d = str[i] - '0';

        for(int j = 0; j < d; ++j)
            cnt += fn(len-1, sumOdd+((flag)? j : 0), sumEven+((flag)? 0 : j));

        sumOdd += (flag)? d : 0;
        sumEven += (flag)? 0 : d;
        --len;
    }

    return cnt;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a > b) swap(a, b);

        printf("%d\n", lucifer(b) - lucifer(a-1));
    }

    return 0;
}
