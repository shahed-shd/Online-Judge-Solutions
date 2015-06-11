#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;

    while(cin >> n) {
        if(n <= 4) cout << "few\n";
        else if(n <= 9) cout << "several\n";
        else if(n <= 19) cout << "pack\n";
        else if(n <= 49) cout << "lots\n";
        else if(n <= 99) cout << "horde\n";
        else if(n <= 249) cout << "throng\n";
        else if(n <= 499) cout << "swarm\n";
        else if(n <= 999) cout << "zounds\n";
        else cout << "legion\n";
    }

    return 0;
}
