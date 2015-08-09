#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long int t, tc;
    long long int w, i;
    bool is_found;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> w;
        is_found = 0;

        if(w & 1L) {
            cout << "Case " << ++tc << ": Impossible\n";
        }
        else {
            for(i = 2; i <= w; i += 2) {
                if(!(w % i)) {
                    if((w / i) & 1L) {
                        cout << "Case " << ++tc << ": " << w/i << ' ' << i << '\n';
                        is_found = 1;
                        break;
                    }
                }
            }

            if(!is_found)
                cout << "Case " << ++tc << ": Impossible\n";
        }
    }

    return 0;
}
