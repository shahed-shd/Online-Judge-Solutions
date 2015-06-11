#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, i, cnt;
    char **p;

    cin >> n;
    cin.ignore(1, '\n');

    p = new char* [n];

    cnt = 0;

    for(i = 0; i < n; ++i) {
        char str[31];
        cin.getline(str, 31);

        p[i] = new char [strlen(str) + 1];
        strcpy(p[i], str);

        for(int j = 0; j < i; ++j) {
            if(!strcmp(p[j], p[i])) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << '\n';

    for(i = 0; i < n; ++i)
        delete [] p[i];

    delete [] p;

    return 0;
}
