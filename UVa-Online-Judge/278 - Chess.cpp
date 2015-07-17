#include <iostream>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while(t--) {
        char piece;
        int row, col, ans;

        cin >> piece >> row >> col;

        if(piece == 'r' || piece == 'Q') ans = min(row, col);
        else if(piece == 'k') ans = (row * col + 1) / 2;   // tricky cases are not appeared as number of rows & columns are from 4 to 10 inclusive.
        else ans = ((row+1)/2) * ((col+1)/2);

        cout << ans << '\n';
    }

    return 0;
}
