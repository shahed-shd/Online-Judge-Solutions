#include <iostream>
#include <vector>
using namespace std;

enum t_shirt {XXL, XL, L, M, S, XS};
typedef     pair<t_shirt, t_shirt>     pr;

vector<t_shirt> distribute;
int n, m, temp;
bool ans;

void bkt(int k, pr arr[])
{
    if(k == m) {
        int sz = distribute.size();
        int cnt[6] = {};

        for(int i = 0; i < sz; ++i)
            ++cnt[distribute[i]];

        int x;
        for(x = 0; x < 6 && cnt[x] <= temp; ++x);

        if(x == 6) ans = true;
        return;
    }

    for(int i = 1; i <= 2; ++i) {
        if(i == 1) distribute.push_back(arr[k].first);
        else distribute.push_back(arr[k].second);

        bkt(k+1, arr);

            if(ans == true) return;

        distribute.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m;

        pr arr[m];

        string str;
        for(int i = 0; i < m; ++i) {
            cin >> str;
            if(str == "XXL") arr[i].first = XXL;
            else if(str == "XL") arr[i].first = XL;
            else if(str == "L") arr[i].first = L;
            else if(str == "M") arr[i].first = M;
            else if(str == "S") arr[i].first = S;
            else if(str == "XS") arr[i].first = XS;

            cin >> str;
            if(str == "XXL") arr[i].second = XXL;
            else if(str == "XL") arr[i].second = XL;
            else if(str == "L") arr[i].second = L;
            else if(str == "M") arr[i].second = M;
            else if(str == "S") arr[i].second = S;
            else if(str == "XS") arr[i].second = XS;
        }

        ans = false;
        distribute.clear();
        temp = n/6;

        bkt(0, arr);

        if(ans == true) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
