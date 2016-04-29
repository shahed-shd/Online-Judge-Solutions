#include <iostream>
using namespace std;

int lcs_len(string &a, string &b)
{
    int m = a.length(), n = b.length();

    int* xx = new int [n+1];
    int* yy = new int [n+1];

    xx[n] = 0;
    for(int i = 0; i <= n; ++i) yy[i] = 0;

    for(int i = m-1; i >= 0; --i) {
        for(int j = n-1; j >= 0; --j) {
            if(a[i] == b[j]) xx[j] = 1 + yy[j+1];
            else xx[j] = max(xx[j+1], yy[j]);
        }

        swap(xx, yy);
    }

    int len = yy[0];

    delete [] xx;
    delete [] yy;

    return len;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);

    string a, b;

    while(getline(cin, a)) {
        getline(cin, b);

        cout << lcs_len(a, b) << '\n';
    }

    return 0;
}
