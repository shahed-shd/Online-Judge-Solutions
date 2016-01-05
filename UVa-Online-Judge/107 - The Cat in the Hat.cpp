#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int h, n;

    while(scanf("%d %d", &h, &n) && (h || n)) {
        if(h == 1) {
            printf("0 %d\n", n);
            continue;
        }

        double temp = log(n) / log(h);
        int N = 1;

        while(fabs(log(N)/log(N+1) - temp) > 10e-10)
            ++N;

        int step;

        if(N > 1)
            step = round(log(n) / log(N) + 1);
        else {
            temp = h / (N+1);

            for(step = 1; round(temp) != 1; ++step)
                temp = temp / (N+1);

            ++step;
        }

        int notWorking;

        if(n > 1)
            notWorking = 1 + round(N * (pow(double(N), step-2) - 1) / (N-1));
        else
            notWorking = step - 1;

        temp = 1.0 * N / (N+1);

        int height = round(h + h * (temp * (pow(temp, step-2) - 1) / (temp - 1)) + n);

        printf("%d %d\n", notWorking, height);
    }

    return 0;
}
