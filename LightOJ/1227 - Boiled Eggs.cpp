#include <iostream>
using namespace std;

int main()
{
    int t, tc, n, p, q, *arr, i, sum, count_eggs;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> n >> p >> q;

        arr = new int [n];
        sum = count_eggs = 0;

        for(i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for(i = 0; i < n; i++) {
            if(sum + arr[i] <= q && count_eggs+1 <= p) {
                sum += arr[i];
                count_eggs++;
            }
            else
                break;
        }

        cout << "Case " << ++tc << ": " << count_eggs << '\n';

        delete [] arr;
    }

    return 0;
}
