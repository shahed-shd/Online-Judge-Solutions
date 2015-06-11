#include <iostream>
using namespace std;

int main()
{
    int n, i;

    cin >> n;

    int arr[n];

    for(i = 0; i < n; ++i) cin >> arr[i];

    i = 0;
    while(i < n) {
        int num = arr[i];
        int cnt = 0;

        while(num == arr[i]) {
            cnt++;
            i++;
        }

        cout << ' ' << cnt << ' ' << num;
    }

    return 0;
}

/*
// managing the space in output. both of these are accepted.

#include <iostream>
using namespace std;

int main()
{
    int n, i;
    bool space;

    cin >> n;

    int arr[n];

    for(i = 0; i < n; ++i) cin >> arr[i];

    space = false;
    i = 0;
    while(i < n) {
        int num = arr[i];
        int cnt = 0;

        while(num == arr[i]) {
            cnt++;
            i++;
        }

        if(!space) {
            cout << cnt << ' ' << num;
            space = true;
        }
        else
            cout << ' ' << cnt << ' ' << num;
    }

    return 0;
}
*/
