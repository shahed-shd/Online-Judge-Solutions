#include <iostream>
using namespace std;

int main()
{
    int k, n, i, cars, cars_remain;

    cin >> k >> n;

    cars_remain = 0;

    for(i = 0; i < n; ++i) {
        cin >> cars;

        cars += cars_remain;

        if(cars > k)
            cars_remain = cars - k;
        else
            cars_remain = 0;
    }

    cout << cars_remain << '\n';

    return 0;
}
