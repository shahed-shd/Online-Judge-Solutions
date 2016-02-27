#include <iostream>
#include <algorithm>
using namespace std;

int  main()
{
    ios::sync_with_stdio(false);

    string str;

    while(cin >> str) {
        string str2;

        for(auto& ch : str)
            if(ch != '+') str2.push_back(ch);

        sort(str2.begin(), str2.end());

        int len = str2.length();

        cout << str2[0];

        for(int i = 1; i < len; ++i)
            cout << '+' << str2[i];

        cout << '\n';
    }

    return 0;
}
