#include <iostream>
using namespace std;

struct info {
    char name[21];
    int length, width, height;
};

int main()
{
    long int t, tc, n, i, thief_index, victim_index, volume, min_vol, max_vol;
    info *p;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> n;

        p = new info [n];

        thief_index = victim_index = 0;
        max_vol = 0;
        min_vol = 1000000;

        for(i = 0; i < n; i++) {
            cin >> p[i].name >> p[i].length >> p[i].width >> p[i].height;

            volume = p[i].length * p[i].width * p[i].height;

            if( max_vol < volume) {
                max_vol = volume;
                thief_index = i;
            }

            if(min_vol > volume) {
                min_vol = volume;
                victim_index = i;
            }
        }

        if(min_vol == max_vol)
            cout << "Case " << ++tc << ": no thief\n";
        else
            cout << "Case " << ++tc << ": " << p[thief_index].name << " took chocolate from " << p[victim_index].name << '\n';
    }

    return 0;
}
