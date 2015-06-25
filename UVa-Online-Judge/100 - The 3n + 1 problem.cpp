#include <iostream>
using namespace std;

int cycle_len(int n)
{
    int cnt = 1;

    while(n > 1) {
        if(n & 1) n = 3 * n + 1;
        else n /= 2;

        ++cnt;
    }

    return cnt;
}

int main()
{
    int i, j, max_cy;

    while(cin >> i >> j) {
        cout << i << ' ' << j << ' ';

        if(i > j) swap(i, j);

        max_cy = 0;
        for(int n = i; n <= j; ++n)
            max_cy = max(max_cy, cycle_len(n));

        cout << max_cy << '\n';
    }

    return 0;
}
