#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i, num, upto, sum, cnt, *arr;

    cin >> n;

    arr = new int [n/2 * 9 + 1];

    for(i = 0; i < n/2 * 9 + 1; i++) arr[i] = 0;    // clearing garvage values.

    upto = pow(10, n/2) - 1;

    for(i = 0; i <= upto; i++) {
        sum = 0;
        num = i;
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        arr[sum]++;
    }

    cnt = 0;
    for(i = 0; i <= upto; i++) {
        sum = 0;
        num = i;
        while(num) {
            sum += num % 10;
            num /= 10;
        }

        cnt += arr[sum];
    }

    cout << cnt << '\n';

    delete [] arr;

    return 0;
}
