#include <iostream>
#include <list>
#include <stack>
using namespace std;

inline bool match(const string &a, const string &b)
{
    return (a[0] == b[0] || a[1] == b[1]);
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);

    string card;

    while(cin >> card, card.front() != '#') {
        list<stack<string> > piles(52);
        auto it = piles.begin();

        it->push(card);
        ++it;

        for( ; it != piles.end(); ++it) {
            cin >> card;
            it->push(card);
        }

        it = piles.begin();
        int idx = 0;

        while(it != piles.end()) {
            if(idx-3 >= 0) {
                auto prev = it;
                --prev, --prev, --prev;

                if(match(prev->top(), it->top())) {
                    prev->push(it->top());
                    it->pop();

                    if(it->empty()) piles.erase(it);

                    it = prev;
                    idx -= 3;
                    continue;
                }
            }

            if(idx-1 >= 0) {
                auto prev = it;
                --prev;

                if(match(prev->top(), it->top())) {
                    prev->push(it->top());
                    it->pop();

                    if(it->empty()) piles.erase(it);

                    it = prev;
                    --idx;
                    continue;
                }
            }

            ++it, ++idx;
        }

        int sz = piles.size();

        cout << sz << ((sz > 1)? " piles " : " pile ") << "remaining:";

        for(auto& x : piles)
            cout << ' ' << x.size();

        cout << '\n';
    }

    return 0;
}
