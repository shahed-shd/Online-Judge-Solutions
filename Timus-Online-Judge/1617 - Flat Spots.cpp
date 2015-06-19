#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    short int n, *arr, i, cnt;

    cin >> n;

    arr = new short int [n];

    for(i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr+n);

    cnt = 0;
    for(i = 0; i < n-1; ++i) {
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2] && arr[i] == arr[i+3]) {
            ++cnt;
            i += 3;
        }
    }

    cout << cnt << '\n';

    delete [] arr;

    return 0;
}
