// Run time: 0.016 sec

#include <cstdio>
using namespace std;

int main()
{
    int m, n;

    while(scanf("%d %d", &m, &n) != EOF)
        printf("%d\n", m*n-1);

    return 0;
}



// ------------------ Alternatively ------------------
// Run time: 0.019 sec
/*

#include <cstdio>
#include <algorithm>
using namespace std;

int dp[305][305];

int divide(int m, int n)
{
    if(m > n) swap(m, n);
    if(n == 1) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    return dp[m][n] = 1 + divide(m, n/2) + divide(m, n - n/2);
}

int main()
{
    int m, n;

    fill(&dp[0][0], &dp[305][0], -1);

    while(scanf("%d %d", &m, &n) != EOF)
        printf("%d\n", divide(m, n));

    return 0;
}

*/
