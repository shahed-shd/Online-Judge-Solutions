#include <iostream>
using namespace std;

int main()
{
    int n;
    long long int ans;

    cin >> n;

    ans = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            ans += i + j;
        }
    }

    cout << ans << '\n';

    return 0;
}
