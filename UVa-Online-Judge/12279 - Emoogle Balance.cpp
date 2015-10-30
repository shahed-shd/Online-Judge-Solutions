#include <iostream>
using namespace std;

int main()
{
    int tc = 0, n;

    while(cin >> n, n != 0) {
        int number;
        int cnt = 0;

        for(int i = 0; i < n; ++i) {
            cin >> number;
            if(number) ++cnt;
        }

        cout << "Case " << ++tc << ": " << cnt - (n-cnt) << '\n';
    }

    return 0;
}
