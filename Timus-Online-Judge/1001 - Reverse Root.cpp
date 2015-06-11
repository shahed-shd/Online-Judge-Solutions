#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int arr[130197];
    int i;

    i = 0;
    while(cin >> arr[i++]);
    i--;

    cout.precision(4);
    fixed(cout);

    while(i) {
        cout << sqrt((long double)(arr[--i])) << '\n';
    }

    return 0;
}
