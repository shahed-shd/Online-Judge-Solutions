#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[1005];

    cin.getline(str, 1005);

    int len = strlen(str);
    int total = 0, cost;

    for(int i = 0; i < len; ++i) {
        if('a' <= str[i] && str[i] <= 'z') {
            cost = str[i] % 3;      // using ASCII code
            total += (cost)? cost : 3;
        }
        else if(str[i] == '.') total += 1;
        else if(str[i] == ',') total += 2;
        else if(str[i] == '!') total += 3;
        else if(str[i] == ' ') total += 1;
    }

    cout << total << '\n';

    return 0;
}
