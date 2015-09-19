#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<short> v;
short minCycle;

int find_res()
{
    int time = minCycle;
    int sz = v.size();
    int cnt = 0;

    while(time <= 3600 && cnt < sz) {
        for(cnt = 0; cnt < sz; ++cnt) {
            if(!(time % (v[cnt]*2) < v[cnt]-5)) break;
        }
        ++time;
    }

    if(--time <= 3600 && cnt == sz) return time;
    else return -1;
}

int main()
{
    int tc = 0;
    string line;

    while(getline(cin, line)) {
        v.clear();
        stringstream ss(line);
        minCycle = 0x7FFF;  // largest value of int of 2 byte (short int).

        short cycle;
        do {
            ss >> cycle;
            v.push_back(cycle);
            minCycle = min(minCycle, cycle);
        }while(!ss.eof());

        int ans = find_res();

        cout << "Set " << ++tc << ' ';
        if(ans == -1) cout << "is unable to synch after one hour.\n";
        else {
            int minute = ans / 60;
            ans %= 60;

            cout << "synchs again at " << minute << " minute(s) and " << ans << " second(s) after all turning green.\n";
        }
    }

    return 0;
}
