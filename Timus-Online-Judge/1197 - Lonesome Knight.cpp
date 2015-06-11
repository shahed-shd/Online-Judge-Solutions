#include <iostream>
using namespace std;

int main()
{
    int n, i, rnk, ans;
    char file;

    cin >> n;

    for(i = 0; i < n; i++) {
        cin >> file >> rnk;

        ans = 0;

        if(file + 2 <= 'h') {
            if(rnk + 1 <= 8) ans++;
            if(rnk - 1 >= 1) ans++;
        }
        if(file - 2 >= 'a') {
            if(rnk + 1 <= 8) ans++;
            if(rnk - 1 >= 1) ans++;
        }
        if(rnk + 2 <= 8) {
            if(file + 1 <= 'h') ans++;
            if(file - 1 >= 'a') ans++;
        }
        if(rnk - 2 >= 1) {
            if(file + 1 <= 'h') ans++;
            if(file - 1 >= 'a') ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
