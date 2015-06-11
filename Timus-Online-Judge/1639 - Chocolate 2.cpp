#include <iostream>
using namespace std;

int main()
{
    int m, n;

    while(cin >> m >> n)
        (m*n % 2)? cout << "[second]=:]\n" : cout << "[:=[first]\n";

    return 0;
}
