#include <iostream>
//#include <cstdio>
#include <cmath>
using  namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    long long int t, k;
    long long int n;
    bool space = false;

    cin >> t;

    while(t--) {
        cin >> k;

        n = (-1 + sqrt(double(8*k-7))) / 2.0;

        if(space)cout << ' '; space = true;

        if(k == n*(n+1)/2+1) cout << '1';
        else cout << '0';
    }

    cout << '\n';

    return 0;
}
