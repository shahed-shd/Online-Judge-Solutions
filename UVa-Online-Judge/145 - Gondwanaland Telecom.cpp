#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

bitset<1441> time_line;    // 24 * 60 = 1440, adding 1 for not considering index 0.

void set_time_line(int start_h, int start_m, int end_h, int end_m)
{
    int start_time = start_h * 60 + start_m;
    int end_time = end_h * 60 + end_m;

    if(start_time < end_time) {
        time_line.reset();
        for(int i = start_time+1; i <= end_time; ++i) time_line.set(i);
    }
    else {
        time_line.set();
        for(int i = end_time+1; i <= start_time; ++i) time_line.reset(i);
    }
}


int main()
{
    char charging_step;

    while(cin >> charging_step, charging_step != '#') {
        string called_number;
        int start_h, start_m, end_h, end_m;

        cin >> called_number >> start_h >> start_m >> end_h >> end_m;

        set_time_line(start_h, start_m, end_h, end_m);

        int minutes_8to18, minutes_18to22, minutes_22to24, minutes_0to8;

        minutes_8to18 = 0;
        for(int i = 8*60+1; i <= 18*60; ++i) minutes_8to18 += time_line[i];

        minutes_18to22 = 0;
        for(int i = 18*60+1; i <= 22*60; ++i) minutes_18to22 += time_line[i];

        minutes_22to24 = 0;
        for(int i = 22*60+1; i <= 24*60; ++i) minutes_22to24 += time_line[i];

        minutes_0to8 = 0;
        for(int i = 1; i <= 8*60; ++i) minutes_0to8 += time_line[i];

        cout.precision(2);
        fixed(cout);

        cout << setw(10) << called_number;
        cout << setw(6) << minutes_8to18;
        cout << setw(6) << minutes_18to22;
        cout << setw(6) << minutes_22to24 + minutes_0to8;
        cout << setw(3) << charging_step;

        cout << setw(8);
        if(charging_step == 'A')
            cout << minutes_8to18 * 0.10 + minutes_18to22 * 0.06 + (minutes_22to24 + minutes_0to8) * 0.02;

        else if(charging_step == 'B')
            cout << minutes_8to18 * 0.25 + minutes_18to22 * 0.15 + (minutes_22to24 + minutes_0to8) * 0.05;

        else if(charging_step == 'C')
            cout << minutes_8to18 * 0.53 + minutes_18to22 * 0.33 + (minutes_22to24 + minutes_0to8) * 0.13;

        else if(charging_step == 'D')
            cout << minutes_8to18 * 0.87 + minutes_18to22 * 0.47 + (minutes_22to24 + minutes_0to8) * 0.17;

        else
            cout << minutes_8to18 * 1.44 + minutes_18to22 * 0.80 + (minutes_22to24 + minutes_0to8) * 0.30;

        cout << '\n';
    }

    return 0;
}
