#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double p;

    cout.precision(0);
    fixed(cout);

    while(cin >> n >> p)
        cout << pow(p, 1.0/n) << '\n';

    return 0;
}


// Alternatively by not using iostream.
/*
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double p;

    while(scanf("%d %lf", &n, &p) != EOF)
        printf("%.0lf\n", pow(p, 1.0/n));

    return 0;
}
*/
