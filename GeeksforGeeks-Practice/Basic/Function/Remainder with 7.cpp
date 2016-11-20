// ==================================================
// Function :   Remainder with 7
// Run time :   0.075 sec.
// Language :   C++11
// ==================================================

int remainderWith7(string n)
{
    int res = 0;

    for(auto& x : n) {
        x -= '0';
        res = (res * 10 + x) % 7;
    }

    return res;
}
