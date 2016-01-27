#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct data {
    int howMany = 0;
    unordered_set<int> whichComp;
    bool isTried = false;
};

unordered_map<char, data> mp;
char computer[10+1];

char input()
{
    char ch;

    while(ch = getchar(), ch != '\n' && ch != EOF) {
        int tmp;
        scanf("%d ", &tmp);
        mp[ch].howMany += tmp;

        while(tmp = getchar(), tmp != ';')
            mp[ch].whichComp.insert(tmp-'0');

        getchar();
    }

    return ch;
}

bool replaceApp(char app)
{
    if(mp[app].isTried) return false;

    for(auto& x : mp[app].whichComp) {
        if(computer[x] == '_') {
            computer[x] = app;
            return true;
        }
    }

    // Now, in case of no vacancy.

    for(auto& x : mp[app].whichComp) {
        if(app != computer[x]) {
            mp[app].isTried = true;

            bool isDone = replaceApp(computer[x]);

            mp[app].isTried = false;

            if(isDone) {
                computer[x] = app;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char input_ch;

    do {
        mp.clear();
        input_ch = input();

        fill_n(computer, 10, '_');
        computer[10] = '\0';

        bool isOK = false;

        for(auto& pr : mp) {
            for(int i = 0; i < pr.second.howMany; ++i) {
                isOK = replaceApp(pr.first);
                if(!isOK) break;;
            }

            if(!isOK) break;
        }

        (isOK)? puts(computer) : puts("!");

    } while(input_ch != EOF);

    return 0;
}
