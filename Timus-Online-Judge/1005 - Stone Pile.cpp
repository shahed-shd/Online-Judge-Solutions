
#include <iostream>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647

int main()
{
    long int n, *w, i, pile1, pile2;

    cin >> n;

    w = new long int [n];

    for(i = 0; i < n; i++) cin >> w[i];

    if(n == 1) cout << w[0] << '\n';
    else if(n == 2) cout << abs(w[0] - w[1]) << '\n';
    else {
        long int bits, mini;

        mini = INT_MAX;

        for(bits = (1L << n) - 1; bits >= 0; bits--) {
            pile1 = pile2 = 0;

            for(i = 0; i < n; i++) {
                if(bits & (1L << i)) pile1 += w[i];
                else pile2 += w[i];
            }

            if(abs(pile1 - pile2) < mini)
                mini = abs(pile1-pile2);
        }

        cout << mini << '\n';
    }

    return 0;
}
