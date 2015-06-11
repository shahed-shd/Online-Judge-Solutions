#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    cout.precision(0);
    fixed(cout);

    cout << a+b << '\n';

    return 0;
}
