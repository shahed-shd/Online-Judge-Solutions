#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string num;
    bool newLine = false;

    while(cin >> num) {
        if(newLine) cout << '\n';
        newLine = true;

        int len = num.length();
        bool isLeapYear, isHuluculu, isBulukulu;

        isLeapYear = isHuluculu = isBulukulu = false;

        for(auto& ch : num) ch -= '0';

        int temp;
        if(num[len-1] == 0 && num[len-2] == 0)      // divisible by 100.
            temp = num[len-4] * 10 + num[len-3];
        else
            temp = num[len-2] * 10 + num[len-1];

        if(temp % 4 == 0) {
            cout << "This is leap year.\n";
            isLeapYear = true;
        }

        if(num[len-1] == 5 || num[len-1] == 0) {    // divisible by 5.
            int sum_of_all_digits = 0;
            for(auto& x : num) sum_of_all_digits += x;

            if(sum_of_all_digits % 3 == 0) {        // divisible by 3. That is, divisible by (5*3).
                cout << "This is huluculu festival year.\n";
                isHuluculu = true;
            }

            if(isLeapYear) {
                int sum = 0;
                for(int i = 0; i < len; i+=2)
                    sum += num[i];

                if((sum_of_all_digits - sum * 2) % 11 == 0) {   // divisible by 11. That is, divisible by (5*11)
                    cout << "This is bulukulu festival year.\n";
                    isBulukulu = true;
                }
            }
        }

        if(!(isLeapYear || isHuluculu || isBulukulu))
            cout << "This is an ordinary year.\n";
    }

    return 0;
}
