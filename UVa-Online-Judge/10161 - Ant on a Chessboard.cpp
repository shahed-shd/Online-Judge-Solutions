#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;

    while(cin >> n, n != 0) {
        int root, nextSquare;

        root = ceil(sqrt(n));
        nextSquare = root * root;

        int x, y;

        if(nextSquare & 1) {    // when nextSquare is odd.
            if(nextSquare - n < root) {
                x = nextSquare - n + 1;
                y = root;
            }
            else {
                x = root;
                y = n - (root-1)*(root-1);
            }
        }
        else {    // when nextSquare is even.
            if(nextSquare - n < root) {
                x = root;
                y = nextSquare - n + 1;
            }
            else {
                x = n - (root-1)*(root-1);
                y = root;
            }
        }

        cout << x << ' ' << y << '\n';
    }

    return 0;
}
