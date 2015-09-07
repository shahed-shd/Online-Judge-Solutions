#include <iostream>
using namespace std;

int main()
{
    long int t, tc, n, i, cnt;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> n;

        cnt = 0;
        for(i = 0; i < 32; i++) {
            if(n & (1L << i)) cnt++;
        }

        if(cnt & 1L) cout << "Case " << ++tc << ": odd\n";
        else cout << "Case " << ++tc << ": even\n";
    }
}
