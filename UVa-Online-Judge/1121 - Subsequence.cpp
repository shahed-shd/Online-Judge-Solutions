// Run time   : 0.000 sec.

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000+3;

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

    int n, s, arr[MAXN];

    while(scanf("%d %d", &n, &s) != EOF) {
        for(int i = 0; i < n; ++i)
            arr[i] = fastIn<int>();

        int len = MAXN, from = 0, sum = 0;

        for(int upto = 0; upto < n; ++upto) {
            sum += arr[upto];

            if(sum >= s) {
                while(sum - arr[from] >= s)
                    sum -= arr[from++];

                len = min(len, upto-from+1);
            }
        }

        printf("%d\n", ((len != MAXN)? len : 0));
    }

    return 0;
}
