#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string a, b;

    cin >> a >> b;

    for(auto& ch : a) ch -= '0';
    for(auto& ch : b) ch -= '0';

    int len1 = a.length(), len2 = b.length();

    int sum[len2+1][2];
    sum[0][0] = sum[0][1] = 0;

    for(int i = 1; i <= len2; ++i) {
        sum[i][0] = sum[i-1][0];
        sum[i][1] = sum[i-1][1];
        ++sum[i][bool(b[i-1])];
    }

    long long ans = 0;
    int temp = len2 - len1 + 1;

    for(int i = 0; i < len1; ++i) {
        ans += sum[temp+i][!a[i]];
        ans -= sum[i][!a[i]];
    }

    cout << ans << '\n';

    return 0;
}
