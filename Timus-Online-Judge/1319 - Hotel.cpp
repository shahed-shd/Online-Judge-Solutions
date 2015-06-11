#include <iostream>
using namespace std;

int main()
{
    int n, nn, *arr, i, r, c, num;

    cin >> n;

    nn = n * n;

    arr = new int [nn];

    num = 1;

    for(i = n-1; i >= 0; i--) {
        for(r = 0, c = i; c < n; r++, c++) {
            *(arr+n*r+c) = num++;           // *(arr+n*r+c) is equivalent to arr[r][c].
        }
    }

    for(i = 1; i < n; i++) {
        for(r = i, c = 0; r < n; r++, c++) {
            *(arr+n*r+c) = num++;
        }
    }

    for(r = 0; r < n; r++) {
        for(c = 0; c < n; c++) {
            cout << *(arr+n*r+c) << ' ';
        }
        cout << '\n';
    }

	delete [] arr;

    return 0;
}
