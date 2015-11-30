#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    unordered_map<char, int> mp;

    for(int i = 0; i <= 9; ++i)
        mp[i+'0'] = i;

    for(int i = 0; i <= 25; ++i)
        mp[i+'A'] = i+10, mp[i+'a'] = i+36;

    string num;

    while(cin >> num) {
        int value, sum_of_digits = 0, maxDigit = -1;

        for(auto& ch : num) {
            value = mp[ch];
            sum_of_digits += value;
            maxDigit = max(maxDigit, value);
        }

        int base = max(2, maxDigit+1);

        // An N-based number R is divisible by (N-1)
        // if and only if the decimal sum of its digits is divisible by (N-1).

        for( ; base <= 62; ++base)
            if(sum_of_digits % (base-1) == 0) break;

        if(base <= 62) cout << base << '\n';
        else cout << "such number is impossible!\n";
    }

    return 0;
}
