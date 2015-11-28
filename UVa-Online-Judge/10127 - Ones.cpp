#include <cstdio>
using namespace std;

int main()
{
    int n;

    while(scanf("%d", &n) == 1) {
        int prev_value = 0;
        int temp;

        for(int i = 1; ; ++i) {
            temp = prev_value * 10 + 1;
            temp %= n;

            if(temp == 0) {
                printf("%d\n", i);
                break;
            }

            prev_value = temp;
        }
    }

    return 0;
}
