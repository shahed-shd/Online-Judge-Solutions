#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

void input_int_line(vector<int> &numbers)
{
    string str;
    getline(cin, str);

    char *pch = strtok((char*) str.c_str(), " ");

    while(pch != NULL) {
        numbers.push_back(atoi(pch));
        pch = strtok(NULL, " ");
    }
}

int main()
{
    int t;
    bool newline = false;

    cin >> t;

    while(t--) {
        cin.ignore(2);

        vector<int> v;
        input_int_line(v);

        int sz = v.size();

        struct {
            string str;
        } float_nums[sz];

        for(int i = 0; i < sz; ++i)
            cin >> float_nums[v[i] - 1].str;

        if(newline) cout << '\n';
        newline = true;

        for(int i = 0; i < sz; ++i)
            cout << float_nums[i].str << '\n';
    }

    return 0;
}
