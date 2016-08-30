// ==================================================
// Problem  :   1303 - Ferris Wheel
// Run time :   0.000 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 20+3;

int n, m, bottomSeat;

int getBottomSeat()
{
    ++bottomSeat;
    if(bottomSeat > m) bottomSeat = 1;
    return bottomSeat;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &n, &m);

        vector<int> line, ferrisWheel(m+1, 0);
        vector<pair<bitset<MAXN>, int> > programmerRecord(n+1, make_pair(bitset<MAXN>(), 0));

        for(int i = 1; i <= n; ++i)
            line.push_back(i);

        bottomSeat = 0;
        int programmerCnt = n, time = 0;

        while(programmerCnt) {
            ++time;

            int seat = getBottomSeat();
            int id = ferrisWheel[seat];

            if(id != 0) {
                if(programmerRecord[id].second < m) line.push_back(id);
                else --programmerCnt;
            }

            id = 0;
            int sz = line.size();

            for(int i = 0; i < sz; ++i) {
                if(programmerRecord[line[i]].first[seat] == false) {
                    id = line[i];
                    line.erase(line.begin()+i);

                    programmerRecord[id].first[seat] = true;
                    ++programmerRecord[id].second;
                    break;
                }
            }

            ferrisWheel[seat] = id;
        }

        printf("Case %d: %d\n", tc, time*5);
    }

    return 0;
}
