#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

short inc_and_ret(short dollar, short k)    // increment & return.
{
    ++dollar;
    if(dollar > k) dollar = 1;
    return dollar;
}

int main()
{
    short n, k;

    while(cin >> n >> k, n != 0 || k != 0) {
        short students[n];
        memset(students, 0, sizeof(students));

        short dollar = 0, remain = 0;
        vector<short> ans;

        while(short(ans.size()) < n) {
            for(short i = 0; i < n; ++i) {
                if(students[i] >= 40) continue;

                if(remain) {
                    students[i] += remain;
                    remain = 0;

                    if(students[i] >= 40) {
                        remain = students[i] - 40;
                        students[i] = 40;
                        ans.push_back(i);
                    }

                    continue;
                }

                dollar = inc_and_ret(dollar, k);

                students[i] += dollar;
                if(students[i] >= 40) {
                    remain = students[i] - 40;
                    students[i] = 40;

                    ans.push_back(i);
                    continue;
                }
            }
        }

        for(unsigned short i = 0; i < n; ++i) {
            cout << setw(3) << ans[i]+1;
        }
        cout << '\n';
    }

    return 0;
}
