// ==================================================
// Problem  :   1021 - Banknotes and Coins
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int main()
{
    const int SZ = 6;
    double notes_frac[SZ] = {100, 50, 20, 10, 5, 2};
    double coins_frac[SZ] = {1, 0.50, 0.25, 0.10, 0.05, 0.01};

    int notes[SZ], coins[SZ];

    for(int i = 0; i < SZ; ++i) {
        notes[i] = notes_frac[i] * 100;
        coins[i] = coins_frac[i] * 100;
    }

    double val_farction;
    scanf("%lf", &val_farction);

    int val = val_farction * 100;

    puts("NOTAS:");

    for(int i = 0; i < SZ; ++i) {
        printf("%d nota(s) de R$ %.2f\n", val / notes[i], notes_frac[i]);
        val %= notes[i];
    }

    puts("MOEDAS:");

    for(int i = 0; i < SZ; ++i) {
        printf("%d moeda(s) de R$ %.2f\n", val / coins[i], coins_frac[i]);
        val %= coins[i];
    }

    return 0;
}
