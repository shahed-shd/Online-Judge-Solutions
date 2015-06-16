#include <iostream>
using namespace std;

int main()
{
    int type, sizes, n, cnt;

    cin >> type >> sizes >> n;

    double well_capacity;

    if(type == 1) well_capacity = sizes * 2;
    else if(type == 2) well_capacity = 1.41421356237 * sizes;    //sqrt(2) = 1.41421356237
    else well_capacity = sizes;

    cnt = 0;
    while(n--) {
        cin >> type >> sizes;

        if(type == 1 && sizes*2 <= well_capacity) cnt++;
        else if(type == 2 && sizes <= well_capacity) cnt++;
        else if(type == 3 && 0.866025403784 * sizes <= well_capacity) cnt++;    // sqrt(3)/2 = 0.866025403784
    }

    cout << cnt << '\n';

    return 0;
}
