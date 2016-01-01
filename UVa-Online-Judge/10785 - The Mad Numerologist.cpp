#include <cstdio>
#include <algorithm>
using namespace std;

void sorting(char *arr, int n, int ini) // Selection Sort algo.
{
    for(int i = ini; i < n; i+=2) {
        int mini = i;

        for(int j = i+2; j < n; j+=2)
            if(arr[j] < arr[mini])
                mini = j;

        if(mini != i)
            swap(arr[i], arr[mini]);
    }
}

void preprocess(char *name)
{
    const char consonants[] = "JSBKTCLDMVNWFXGPYHQZR";
    const char vowels[] = "AUEOI";

    for(int j = 0, i = 0; i < 5; ++i) {
        int cnt = 21;
        while(cnt--) {
            name[j] = vowels[i];
            j += 2;
        }
    }

    for(int j = 1, i = 0; i < 21; ++i) {
        int cnt = 5;
        while(cnt--) {
            name[j] = consonants[i];
            j += 2;
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char name[211];
    preprocess(name);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        char ans[211];

        for(int i = 0; i < n; ++i)
            ans[i] = name[i];
        ans[n] = '\0';

        sorting(ans, n, 0);
        sorting(ans, n, 1);

        printf("Case %d: %s\n", tc, ans);
    }

    return 0;
}
