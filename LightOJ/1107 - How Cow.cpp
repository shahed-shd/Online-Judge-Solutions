#include <iostream>
using namespace std;

int main()
{
    int t, tc, x1, y1, x2, y2, m, i, x, y;
    bool *arr;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> x1 >> y1 >> x2 >> y2;

        cin >> m;

        arr = new bool [m];

        for(i = 0; i < m; i++) {
            cin >> x >> y;

            if(x > x1 && x < x2 && y > y1 && y < y2)
                arr[i] = 1;
            else
                arr[i] = 0;
        }

        cout << "Case " << ++tc << ":\n";
        for(i = 0; i < m; i++) {
            if(arr[i])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
	
		delete [] arr;
    }

    return 0;
}
