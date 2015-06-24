#include <iostream>
#include <cstring>
using namespace std;

#define SZ 96       // 127-31 = 96

int find_min(int *arr, int &min_freq)
{
    int idx = -1;

    min_freq = 1001;

    for(int i = SZ - 1; i >= 0; --i) {
        if(min_freq > arr[i] && arr[i] > 0) {
            min_freq = arr[i];
            idx = i;
        }
    }

    return idx;
}

int main()
{
    int arr[SZ];
    string str;
    bool newline = false;

    while(getline(cin, str)) {
        int len = str.length();

        memset(arr, 0, sizeof(arr));

        for(int i = 0; i < len; ++i) {
            ++arr[str[i] - 32];
        }

        if(newline) cout << '\n';
        newline = true;

        int idx, freq;

        while(idx = find_min(arr, freq), idx >= 0) {
            cout << idx+32 << ' ' << freq << '\n';
            arr[idx] = 0;
        }
    }

    return 0;
}
