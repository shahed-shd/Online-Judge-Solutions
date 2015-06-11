#include <iostream>
using namespace std;

int arr[100000];

int find_max(int n)
{
    int maximum = 0;

    for(int i = 0; i <= n; i++)
        if(maximum < arr[i]) maximum = arr[i];

    return maximum;
}

int main()
{
    int n[11], i, idx;

    arr[0] = 0;
    arr[1] = 1;

    for(idx = 2; idx < 100000; idx++) {
        if(idx & 1) {       // when idx is odd.
            i = (idx-1) / 2;
            arr[idx] = arr[i] + arr[i+1];
        }
        else {              // when idx is even.
            i = idx / 2;
            arr[idx] = arr[i];
        }
    }

    i = 0;
    while(cin >> n[i], n[i++] != 0);

    i--;
    idx = i;

    for(i = 0; i < idx; i++) {
        cout << find_max(n[i]) << '\n';
    }

    return 0;
}
