/* Run time: 0.003 sec */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[15];
    int num;

    while(scanf("%s", str), str[0] != '-') {
        if(strlen(str) > 2 && (str[1] == 'x' || str[1] == 'X')) {
            sscanf(str, "%x", &num);
            printf("%d\n", num);
        }
        else {
            sscanf(str, "%d", &num);
            printf("0x%X\n", num);
        }
    }
    return 0;
}


/* Alternatively in C++ */
/* Run time: 0.029 sec */
/*
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    unsigned num;
    string str;
    istringstream iss;

    cout.setf(ios::uppercase);

    while(cin >> str, str[0] != '-') {
        iss.str(str);

        if(str[1] == 'x' || str[1] == 'X') {
            iss.unsetf(ios::dec);
            iss.setf(ios::hex);

            iss >> num;

            cout << num << '\n';

            iss.unsetf(ios::hex);
            iss.setf(ios::dec);
        }
        else {
            iss >> num;

            cout.unsetf(ios::dec);
            cout.setf(ios::hex);

            cout << "0x" << num << '\n';

            cout.unsetf(ios::hex);
            cout.setf(ios::dec);
        }

        iss.clear();
    }

    return 0;
}
*/
