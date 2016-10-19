// ==================================================
// Problem  :   732C - Sanatorium
// Run time :   0.031 sec.
// Language :   C++14
// ==================================================

#include <iostream>
#include <climits>
using namespace std;

typedef     unsigned long long      ULL;

inline ULL f(ULL b, ULL d, ULL s)
{
    ULL mx = max(max(b, d), s);
    ULL ret = (mx - b) + (mx - d) + (mx - s);

    if(s < mx) ret -= 1;
    if(s < mx && d < mx ) ret -= 1;

    return ret;
}

int main()
{
    ULL b, d, s;
    cin >> b >> d >> s;

    ULL ans = LLONG_MAX;

    ans = min(ans, f(b, d, s));
    ans = min(ans, f(b+1, d, s));
    ans = min(ans, f(b+1, d+1, s));

    cout << ans << '\n';

    return 0;
}
