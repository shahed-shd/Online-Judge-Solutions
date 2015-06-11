#include <iostream>
using namespace std;

int main()
{
    int n, i;

    cin >> n;

    char arr[n][2], ch;

    for(i = 0; i < n; ++i) cin >> arr[i][0] >> arr[i][1];
    cin >> ch;

    for(i = 0; i < n; ++i)
        if(arr[i][0] == ch) cout << arr[i][0] << arr[i][1] << '\n';

    return 0;
}
