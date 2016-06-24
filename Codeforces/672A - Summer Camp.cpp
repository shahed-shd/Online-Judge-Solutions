#include <cstdio>
using namespace std;

int main()
{
    int n;

    while(scanf("%d", &n) != EOF) {
        int ans;

        if(n <= 9) {
            ans = n;
        }
        else if(n <= 189) {     // 9 + (99-9)*2
            int tmp = n - 9;
            int num = 9 + tmp/2 + ((tmp & 1)? 1 : 0);
            ans = (tmp & 1)? (num / 10) : (num % 10);
        }
        else {
            int tmp = n - 189;
            int num = 99 + tmp/3 + ((tmp % 3)? 1 : 0);

            if(tmp % 3 == 1)
                ans = num / 100;
            else if(tmp % 3 == 2)
                ans = (num % 100) / 10;
            else                // tmp % 3 == 0
                ans = num % 10;
        }

        printf("%d\n", ans);
    }

    return 0;
}
