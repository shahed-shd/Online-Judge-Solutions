#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int t, tc, i, len;
    char str[105];

    cin >> t;
    cin.ignore(1, '\n');
    tc = 0;

    while(t--) {
        short arr1[26] = {0}, arr2[26] = {0};

        cin.getline(str, 105);

        len = strlen(str);

        for(i = 0; i < len; i++) {
            if('A' <= str[i] && str[i] <= 'Z')
                arr1[str[i] - 'A'] += 1;
            else if(str[i] != ' ')
                arr1[str[i] - 'a'] += 1;
        }

        cin.getline(str, 105);

        len = strlen(str);

        for(i = 0; i < len; i++) {
            if('A' <= str[i] && str[i] <= 'Z')
                arr2[str[i] - 'A'] += 1;
            else if(str[i] != ' ')
                arr2[str[i] - 'a'] += 1;
        }

        for(i = 0; i < 26 && arr1[i] == arr2[i]; i++);

        cout << "Case " << ++tc << ": ";
        if(i == 26) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
