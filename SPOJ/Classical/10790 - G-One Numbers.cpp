#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;

const int MAXS = 85, MAXP = 10;

bitset<100> isPrime;
int memo[MAXS][MAXP];

// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97.
void getPrimes()
{
    isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = isPrime[11] =
    isPrime[13] = isPrime[17] = isPrime[19] = isPrime[23] = isPrime[29] =
    isPrime[31] = isPrime[37] = isPrime[41] = isPrime[43] = isPrime[47] =
    isPrime[53] = isPrime[59] = isPrime[61] = isPrime[67] = isPrime[71] =
    isPrime[73] = isPrime[79] = isPrime[83] = isPrime[89] = isPrime[97] = true;
}

int fn(int digitSum, int pos)
{
    if(pos == 0) return isPrime[digitSum];

    if(memo[digitSum][pos] != -1) return memo[digitSum][pos];

    int cnt = 0;

    for(int i = 0; i <= 9; ++i)
        cnt += fn(digitSum+i, pos-1);

    return memo[digitSum][pos] = cnt;
}

int G_one_count(int n)
{
    ++n;

    char str[15];
    sprintf(str, "%d", n);
    int len = strlen(str);

    int digitSum = 0, cnt = 0;

    for(int i = 0; str[i]; ++i) {
        --len;
        int d = str[i] - '0';

        for(int j = 0; j < d; ++j)
            cnt += fn(digitSum+j, len);

        digitSum += d;
    }

    return cnt;
}


int main()
{
    getPrimes();

    int tc;
    scanf("%d", &tc);

    fill(&memo[0][0], &memo[MAXS][0], -1);

    while(tc--) {
        int f, t;
        scanf("%d %d", &f, &t);

        printf("%d\n", G_one_count(t) - G_one_count(f-1));
    }

    return 0;
}

