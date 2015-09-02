#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string number;
    stringstream ss;

    while(cin >> number, number != "END") {
        int digit, cnt = 0;

        while(true) {
            digit = number.length();
            ++cnt;

            ss.str(string()); ss.clear();   //to discard old data.

            ss << digit;

            if(ss.str() == number) break;

            ss >> number;
        }

        cout << cnt << '\n';
    }

    return 0;
}
