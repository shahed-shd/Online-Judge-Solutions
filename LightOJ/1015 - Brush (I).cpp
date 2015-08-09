#include <iostream>
using namespace std;

int main() {
    int t, caseno, n, dust, sum;

    cin >> t;
    caseno = 0;

    while(t--) {
        cin >> n;
        sum = 0;

        while(n--) {
            cin >> dust;
            if(dust > 0) sum += dust;
        }
        cout << "Case " << ++caseno << ": " << sum << '\n';
    }
    return 0;
}
