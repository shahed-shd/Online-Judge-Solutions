#include <iostream>
using namespace std;

#define ULL unsigned long long int

int main()
{
    ULL n, m;

    while(cin >> m >> n, m != 0 || n != 0) {
        ULL mini, maxi;

        mini = min(m, n);
        maxi = max(m, n);

        ULL res;

        --mini;
        res = mini*(mini+1)*(mini-1)/3; // x*(x+1)*(2*x+1)/6 - x*(x+1)/2 = x*(x+1)*(x-1)/3;
        res *= 2;
        ++mini;

        res += (mini-1) * mini * (maxi - mini + 1);

        res *= 2; // two diagonals.

        res += n * (m - 1) * m + m * (n - 1) * n; // horizontal & vertical

        cout << res << '\n';
    }

    return 0;
}
