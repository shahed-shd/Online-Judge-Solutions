#include <iostream>
using namespace std;

struct info {
    string name;
    int amount;
};

int main()
{
    int n;
    bool newline = false;

    while(cin >> n) {
        info friends[n];

        for(int i = 0; i < n; ++i) {
            cin >> friends[i].name;
            friends[i].amount = 0;
        }

        string str;
        int money, persons, who_gives, who_receives, money_to_each;

        for(int i = 0; i < n; ++i) {
            cin >> str >> money >> persons;

            if(money == 0) {
                for(int j = 0; j < persons; ++j) cin >> str;    //just taking names, but nothing to do.
                continue;
            }

            if(persons == 0) continue;

            for(who_gives = 0; who_gives < n && str.compare(friends[who_gives].name); ++who_gives);   //finding who gives the gift.

            friends[who_gives].amount -= money;
            friends[who_gives].amount += money % persons;
            money_to_each = money / persons;

            for(int j = 0; j < persons; ++j) {
                cin >> str;
                for(who_receives = 0; who_receives < n && str.compare(friends[who_receives].name); ++who_receives);
                friends[who_receives].amount += money_to_each;
            }
        }

        if(newline) cout << '\n';
        newline = true;

        for(int i = 0; i < n; ++i)
            cout << friends[i].name << ' ' << friends[i].amount << '\n';
    }

    return 0;
}
