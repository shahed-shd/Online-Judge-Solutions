#include <iostream>
using namespace std;

int main()
{
    int s;
    long long int d;

    while(cin >> s >> d) {
        long long n = 1;

        while(n*(2*s+(n-1)) < 2*d) {
            ++n;
        }

        cout << s+(n-1) << '\n';

    }

    return 0;
}
