#include <iostream>
using namespace std;

int main()
{
    int n, i, e, l, m;
    char str[17];

    cin >> n;
    cin.ignore(1, '\n');

    e = l = m = 0;
    for(i = 0; i < n; ++i) {
        cin.getline(str, 17);
        if(str[0] == 'E') e++;
        else if(str[0] == 'L') l++;
        else m++;
    }

    int maxm = max(e, max(l, m));

    if(maxm == e) cout << "Emperor Penguin\n";
    else if(maxm == l) cout << "Little Penguin\n";
    else cout << "Macaroni Penguin\n";

    return 0;
}
