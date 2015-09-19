#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> v;
int minCycle;

int get_res()
{
    int time = minCycle * 2;
    int sz = v.size();
    int cnt = 0;

    while(cnt < sz && time <= 3600*5) {
        for(cnt = 0; cnt < sz; ++cnt) {
            if(!(time % (v[cnt]*2) < v[cnt]-5)) break;
        }
        ++time;
    }

    if(--time <= 3600*5 && cnt == sz) return time;
    else return -1;
}

int main()
{
    int t1, t2, t3;

    while(cin >> t1 >> t2 >> t3, t1 || t2 || t3) {
        v.clear();

        v.push_back(t1);
        minCycle = t1;

        v.push_back(t2);
        if(t2 < minCycle) minCycle = t2;

        if(t3) {
            v.push_back(t3);
            if(t3 < minCycle) minCycle = t3;

            while(cin >> t3, t3  != 0) {
                v.push_back(t3);
                if(t3 < minCycle) minCycle = t3;
            }
        }

        int ans = get_res();

        if(ans == -1) cout << "Signals fail to synchronise in 5 hours\n";
        else {
            int h, m;
            h = ans / 3600;
            ans %= 3600;

            m = ans / 60;
            ans %=  60;

            cout.fill('0');
            cout << setw(2) << h << ':'
                << setw(2) << m << ':'
                << setw(2) << ans << '\n';
        }
    }

    return 0;
}
