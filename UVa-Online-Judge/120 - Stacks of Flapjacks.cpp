#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

const int MAXN = 30+3;

int pancakes[MAXN];

void flipRange(int r1, int r2)
{
    while(r1 < r2)
        swap(pancakes[r1++], pancakes[r2--]);
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);

    string str;

    while(getline(cin, str), !str.empty()) {
        cout << str << '\n';
        stringstream ss(str);

        int n = 0;

        while(ss >> pancakes[n]) ++n;

        int sorted[n];
        copy(pancakes, pancakes+n, sorted);
        sort(sorted, sorted+n);

        for(int i = n-1; i >= 0; --i) {
            if(sorted[i] == pancakes[i]) continue;  // Already in the correct position.

            int idx = find(pancakes, pancakes+n, sorted[i]) - pancakes;

            if(idx != 0) {          // Target pancake is not on top.
                flipRange(0, idx);
                cout << n-idx << ' ';
            }

            flipRange(0, i);
            cout << n-i << ' ';
        }

        cout << "0\n";
    }

    return 0;
}
