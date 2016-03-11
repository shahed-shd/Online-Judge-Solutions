#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int day[3], hour[3], minute[3], second[3];

    for(int i = 0; i < 2; ++i)
        scanf("Dia %d\n%d : %d : %d\n", &day[i], &hour[i], &minute[i], &second[i]);

    int duration = (day[1]-1) * 86400 + (hour[1]-1) * 3600 + (minute[1]-1) * 60 + second[1]; // 60 * 60 * 24 = 86400.
    duration -= (day[0]-1) * 86400 + (hour[0]-1) * 3600 + (minute[0]-1) * 60 + second[0];

    day[2] = duration / 86400;
    duration %= 86400;

    hour[2] = duration / 3600;
    duration %= 3600;

    minute[2] = duration / 60;
    duration %= 60;

    second[2] = duration;

    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", day[2], hour[2], minute[2], second[2]);

    return 0;
}
