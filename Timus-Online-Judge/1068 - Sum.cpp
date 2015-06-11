#include <iostream>
using namespace std;

int main()
{
    long int n, sum;

    cin >> n;

    if(n > 0) {
        sum = n * (n+1) / 2;
    }
    else {
        n = -n;
        sum = n * (n+1) / 2;
        sum = -sum;
        sum += 1;
    }

    cout << sum << '\n';

    return 0;
}
