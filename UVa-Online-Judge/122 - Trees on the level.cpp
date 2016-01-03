#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

typedef     pair<string,int>    strI;

vector<strI> vec;

vector<bool> isLinked;  // used in check().
unordered_set<string> pathSet;
bool isInvalid;

bool check(string path, int idx)
{
    bool flag = false;

    for(int i = idx; i >= 0; --i) {
        if(path == vec[i].first) {
            if(isLinked[i]) flag = true;
            else if(path.size()){
                path.pop_back();
                flag = check(path, i-1);
            }

            break;
        }
    }

    if(flag) isLinked[idx+1] = true;

    return flag;
}

bool isValidTree()
{
    if(vec[0].first.length()) return false;

    isLinked.assign(vec.size(), false);
    isLinked[0] = true;

    for(int i = vec.size()-1; i > 0; --i) {
        if(!isLinked[i]) {
            string temp(vec[i].first);
            temp.pop_back();

            if(!check(temp, i-1)) return false;
        }
    }

    return true;
}

void process_str(string str)
{
    str = str.substr(1, str.length()-2);

    int val = -1;
    char temp[300] = "";

    if('0' <= str.front() && str.front() <= '9') {
        if(str.back() == 'L' || str.back() == 'R')
            sscanf(str.c_str(), "%d,%s", &val, temp);
        else
            sscanf(str.c_str(), "%d", &val);
    }
    else {
        isInvalid = true;
        return;
    }

    str = string(temp);

    if(val < 0 || pathSet.find(str) != pathSet.end()) {
        isInvalid = true;
        return;
    }

    pathSet.insert(str);

    vec.push_back(make_pair(str, val));
}

int main()
{
    ios::sync_with_stdio(false);

    string str;

    while(cin >> str) {
        vec.clear();
        isLinked.clear();
        pathSet.clear();

        isInvalid = false;

        process_str(str);

        while(cin >> str, str != "()")
            process_str(str);

        sort(vec.begin(), vec.end(),
            [](strI a, strI b)      // lambda function.
            { return ((a.first.length() == b.first.length())? (a.first < b.first) : (a.first.length() < b.first.length())); }
        );

        if(isInvalid || !isValidTree()) {
            cout << "not complete\n";
            continue;
        }

        int sz = vec.size();

        cout << vec[0].second;
        for(int i = 1; i < sz; ++i)
            cout << ' ' << vec[i].second;

        cout << '\n';
    }

    return 0;
}
