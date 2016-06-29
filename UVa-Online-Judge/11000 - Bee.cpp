#include <cstdio>
#include <vector>
using namespace std;

typedef     long long       LL;

vector<LL> memo;

void preprocess()
{
    memo.push_back(0);
    memo.push_back(1);

    LL lim = 1LL << 32;

    for(int i = 2; memo.back() <= lim; ++i)
        memo.push_back(memo[i-1] + memo[i-2] + 1);
}

int main()
{
    preprocess();

    int n;

    while(scanf("%d", &n), n != -1)
        printf("%lld %lld\n", memo[n], memo[n+1]);

    return 0;
}
