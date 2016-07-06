#include <iostream>
#include <algorithm>
using namespace std;

int base;
string digitList, tmp, ans;

void fn(unsigned len)
{
    if(len > ans.length() || (len == ans.length() && tmp > ans)) {
        ans = tmp;
    }

    ++len;
    int num = 0;

    for(auto &x : tmp)
        num = (num * base + (x - '0')) % len;

    num = (num * base) % len;

    for(auto &x : digitList) {
        if(x == '0' && len == 1) continue;

        if((num + (x-'0')) % len == 0) {
            tmp.push_back(x);
            fn(len);
            tmp.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> base >> digitList) {
        ans.clear();

        sort(digitList.begin(), digitList.end());
        digitList.erase(unique(digitList.begin(), digitList.end()), digitList.end());

        fn(0);

        cout << ans << '\n';
    }

    return 0;
}
