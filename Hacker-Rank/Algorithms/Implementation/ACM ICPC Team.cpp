#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int MAXM = 500 + 3;

int main()
{
    //freopen("in", "r", stdin);

    ios::sync_with_stdio(false);
    int n, m;

    while(cin >> n >> m) {
        vector<bitset<MAXM> > V(n);
        string str;

        for(int i = 0; i < n; ++i) {
            cin >> str;

            int len = str.length();

            bitset<MAXM> &curr = V[i];

            for(int j = 0; j < len; ++j)
                if(str[j] == '1')
                    curr[j] = true;
        }

        int maxTopicCnt = -1, maxTeamCnt;

        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                int currTopicCnt = (V[i] | V[j]).count();

                if(currTopicCnt > maxTopicCnt) {
                    maxTopicCnt = currTopicCnt;
                    maxTeamCnt = 1;
                }
                else if(currTopicCnt == maxTopicCnt) {
                    ++maxTeamCnt;
                }
            }
        }

        cout << maxTopicCnt << '\n' << maxTeamCnt << '\n';
    }

    return 0;
}
