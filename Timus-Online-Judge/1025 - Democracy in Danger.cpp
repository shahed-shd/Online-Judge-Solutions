#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k, *arr, i, half_more, ans;

    cin >> k;

    arr = new int [k];

    for(i = 0; i < k; i++) cin >> arr[i];

    sort(arr, arr+k);

    half_more = k/2+1;

    ans = 0;

    for(i = 0; i < half_more; i++) {
        ans += arr[i]/2+1;
    }

    cout << ans << '\n';

    delete [] arr;

    return 0;
}
