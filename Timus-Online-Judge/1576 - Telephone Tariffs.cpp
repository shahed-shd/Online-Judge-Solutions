#include <iostream>
using namespace std;

int main()
{
    int n1, c1, n2, t, c2, n3, k, mm, ss, total_mm;

    cin >> n1 >> c1 >> n2 >> t >> c2 >> n3 >> k;

    total_mm = 0;

    for(int i = 0; i < k; ++i) {
        cin >> mm;
        cin.ignore(1, ':');
        cin >> ss;

        if(mm == 0 && ss <= 6) continue;

        if(ss) ++mm;

        total_mm += mm;
    }

    cout << "Basic:     " << n1 + total_mm * c1;
    cout << "\nCombined:  " << n2 + max(0, total_mm - t) * c2;
    cout << "\nUnlimited: " << n3 << '\n';

    return 0;
}
