#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int main()
{
    long long int arr[9], mini, totalBottle, movement;
    char color[4];

    while(cin >> arr[0]) {
        totalBottle = arr[0];

        for(int i = 1; i < 9; ++i) {
            cin >> arr[i];
            totalBottle += arr[i];
        }

        mini = INT_MAX;

        movement = totalBottle - arr[0] - arr[5] - arr[7];                  // BCG
        if(movement < mini ) { mini = movement; strcpy(color, "BCG"); }

        movement = totalBottle - arr[0] - arr[4] - arr[8];                  // BGC
        if(movement < mini ) { mini = movement; strcpy(color, "BGC"); }

        movement = totalBottle - arr[2] - arr[3] - arr[7];                  // CBG
        if(movement < mini ) { mini = movement; strcpy(color, "CBG"); }

        movement = totalBottle - arr[2] - arr[4] - arr[6];                  // CGB
        if(movement < mini ) { mini = movement; strcpy(color, "CGB"); }

        movement = totalBottle - arr[1] - arr[3] - arr[8];                  // GBC
        if(movement < mini ) { mini = movement; strcpy(color, "GBC"); }

        movement = totalBottle - arr[1] - arr[5] - arr[6];                  // GCB
        if(movement < mini ) { mini = movement; strcpy(color, "GCB"); }

        cout << color << ' ' << mini << '\n';
    }

    return 0;
}
