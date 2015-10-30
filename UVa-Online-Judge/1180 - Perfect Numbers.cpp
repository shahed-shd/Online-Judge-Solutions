#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int sq = sqrt(n);
    for(int i = 3; i <= sq; i+=2) {
        if(n % i == 0) return false;
    }

    return true;
}

int main()
{
    int n, p;
    cin >> n;

    while(n--) {
        cin >> p;
        if(n) cin.ignore(1, ',');

        if(is_prime(p) && is_prime(pow(2,p)-1)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
