#include <iostream>
#include <cmath>
using namespace std;

#define PI acos(-1)

int main()
{
    long int n, i;
    double r, *x, *y, ans;

    cin >> n >> r;

    x = new double [n];
    y = new double [n];

    for(i = 0; i < n; i++) cin >> x[i] >> y[i];

    ans = 0;

    for(i = 1; i < n; i++)
        ans += sqrt( (x[i]-x[i-1])*(x[i]-x[i-1]) + (y[i]-y[i-1])*(y[i]-y[i-1]) );

    ans += sqrt( (x[0]-x[n-1])*(x[0]-x[n-1]) + (y[0]-y[n-1])*(y[0]-y[n-1]) );

    ans += 2 * PI * r;

    cout.precision(2);
    fixed(cout);

    cout << ans << '\n';

    return 0;
}
