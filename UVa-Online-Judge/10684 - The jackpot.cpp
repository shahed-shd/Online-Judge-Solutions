#include <iostream>
using namespace std;

int main()
{
    int n;

    while(cin >> n, n > 0) {
        int maxGain, bet, currentMaxGain;

        maxGain = currentMaxGain = 0;

        while(n--) {
            cin >> bet;

            currentMaxGain += bet;

            if(currentMaxGain > maxGain)
                maxGain = currentMaxGain;

            if(currentMaxGain < 0)
                currentMaxGain = 0;
        }

        if(maxGain > 0)
            cout << "The maximum winning streak is " << maxGain << ".\n";
        else
            cout << "Losing streak.\n";
    }

    return 0;
}
