#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;

    while(cin >> str, str != "#") {
        if(next_permutation(str.begin(), str.end()))
            cout << str << '\n';
        else
            cout << "No Successor\n";
    }

}

// Alternativly by not using next_permutation().
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;

    while(getline(cin, str), str != "#") {
        int i, j, len = str.length();

        for(i = len-2; str[i] >= str[i+1] && i >= 0; --i);

        if(i < 0) {
            cout << "No Successor\n";
            continue;
        }

        for(j = len-1; str[i] >= str[j]; --j);

        swap(str[i], str[j]);

        reverse(&str[i+1], &str[len]);

        cout << str << '\n';
    }

    return 0;
}
*/
