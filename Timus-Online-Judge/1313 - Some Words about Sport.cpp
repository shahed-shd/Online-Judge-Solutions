#include <iostream>
using namespace std;

int main()
{
    int n, nn, i, r, c, *arr, *ans, idx;

    cin >> n;

    nn = n * n;

    arr = new int [nn];
    ans = new int [nn];

    for(i = 0; i < nn; i++) cin >> arr[i];

    idx = 0;

    for(i = 0; i < n; i++) {
        r = i;
        c = 0;
        while(r >= 0) {
            ans[idx++] = *(arr+n*r+c);      //*(arr+n*r+c) is equivalent to arr[r][c].
            r--;
            c++;
        }
    }

    for(i = 1; i < n; i++) {
        r = n-1;
        c = i;
        while(c < n) {
            ans[idx++] = *(arr+n*r+c);
            r--;
            c++;
        }
    }

    for(i = 0; i < nn-1; i++) cout << ans[i] << ' ';

    cout << ans[i] << '\n';

	delete [] arr;
	delete [] ans;

    return 0;
}
