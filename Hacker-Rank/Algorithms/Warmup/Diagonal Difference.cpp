#include <cstdio>
#include <cstdlib>
using namespace std;

typedef     long long       LL;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

int main()
{
    //freopen("in", "r", stdin);

    int n;

    while(~scanf("%d", &n)) {
        int arr[n][n];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                arr[i][j] = fastIn<int>();

        LL res = 0;

        for(int i = 0; i < n; ++i)
            res += arr[i][i] - arr[i][n-1-i];

        printf("%lld\n", abs(res));
    }

    return 0;
}
