#include <iostream>
using namespace std;

int main()
{
    long int t, tc, n, donate, amount, *arr, index, i;
    char str[7];

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> n;

        arr = new long int [n];
        amount = index = 0;

        while(n--) {
            cin >> str;

            if(*str == 'd') {
                cin >> donate;
                amount += donate;
            }
            else {
                arr[index++] = amount;
            }
        }

        cout << "Case " << ++tc << ":\n";
        for(i = 0; i < index; i++) {
            cout << arr[i] << '\n';
        }

        delete [] arr;
    }

    return 0;
}
