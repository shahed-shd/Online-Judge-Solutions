#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, char> record;

    int n, capacity, now_at_room, id;
    char sign;

    cin >> n;

    capacity = now_at_room = 0;

    while(n--) {
        cin >> sign >> id;

        record[id];

        if(sign == '+') {
            record[id] = '+';

            ++now_at_room;
            if(now_at_room > capacity) capacity = now_at_room;
        }
        else {  // when sign is '-'
            if(record[id] == '\0') ++capacity;  // means that the id was in the room from the begining. that's why no sign is assigned.
            else {
                record[id] = '-';

                --now_at_room;
            }
        }
    }

    cout << capacity << '\n';

    return 0;
}
