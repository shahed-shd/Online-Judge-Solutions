#include <iostream>
using namespace std;

int main()
{
    int b, r, y, k, i, ans;
    char str[7];

    cin >> b >> r >> y;
    cin >> k;

    ans = 1;

    for(i = 0; i < k; ++i) {
        cin >> str;

        if(*str == 'B') ans *= b;
        else if(*str == 'R') ans *= r;
        else ans *= y;

    }

    cout << ans << '\n';

    return 0;
}
