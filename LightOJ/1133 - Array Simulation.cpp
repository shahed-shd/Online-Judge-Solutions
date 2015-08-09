// strange experience, LightOJ compiler shows 'Wrong Answer' while swapping by using bit wise operator.
// today date: 04-06-2015.

#include <iostream>
using namespace std;

int main()
{
    long int t, tc, n, m, *arr, i, a, b, temp;
    char ch;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> n >> m;

        arr = new long int [n];

        for(i = 0; i < n; i++) {
            cin >> arr[i];
        }

        while(m--) {
            cin >> ch;

            switch(ch) {
                case 'S':
                    cin >> a;
                    for(i = 0; i < n; i++) arr[i] += a;
                    break;
                case 'M':
                    cin >> a;
                    for(i = 0; i < n; i++) arr[i] *= a;
                    break;
                case 'D':
                    cin >> a;
                    for(i = 0; i < n; i++) arr[i] /= a;
                    break;
                case 'R':
                    for(i = 0; i < n/2; i++) {
                        //arr[i] ^= arr[n-i-1];
                        //arr[n-i-1] ^= arr[i];
                        //arr[i] ^= arr[n-i-1];
                        temp = arr[i];
                        arr[i] = arr[n-i-1];
                        arr[n-i-1] = temp;
                    }
                    break;
                case 'P':
                    cin >> a >> b;

                    //arr[a] ^= arr[b];
                    //arr[b] ^= arr[a];
                    //arr[a] ^= arr[b];
                    temp = arr[a];
                    arr[a] = arr[b];
                    arr[b] = temp;
                    break;
                default:
                    break;
            }
        }

        cout << "Case " << ++tc << ":\n";

        for(i = 0; i < n-1; i++) {
            cout << arr[i] << ' ';
        }
        cout << arr[i] << '\n';

        delete [] arr;
    }

    return 0;
}
