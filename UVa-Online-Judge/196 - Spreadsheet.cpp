#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
using namespace std;

#define     matrix(i,j)     (*(matrix+col*i+j))

int col;
int *matrix;
unordered_map<int, vector<int> > dependent;
vector<vector<int> > adjList;
vector<int> indegree;

int getValue(string str)
{
    int len = str.length(), res = 0;
    for(int i = 0; i < len; ++i) {
        res *= 26;
        res += str[i] - 'A' + 1;
    }
    return res;
}

void processTheString(string str, int i, int j)
{
    str.front() = ' ';
    str.push_back('+');

    for(unsigned i = 0; i < str.length(); ++i) {
        if('1' <= str[i] && str[i] <= '9') {
            str.insert(i, 1, ' ');
            while(str[i] != '+') { ++i; };
            str[i] = ' ';
        }
    }

    str.pop_back();

    stringstream ss(str);
    string str1;
    int r, c, from, to;

    while(!ss.eof()) {
        ss >> str1;
        c = getValue(str1)-1;
        ss >> r;
        --r;

        from = col*r+c;
        to = col*i+j;

        adjList[from].push_back(to);
        dependent[to].push_back(from);
        ++indegree[to];
    }
}

void topologicalSort(int n)
{
    queue<int> q;

    for(int i = 0; i < n; ++i)
        if(!indegree[i]) q.push(i);

    int u, v, sz;
    while(!q.empty()) {
        u = q.front(); q.pop();
        sz = adjList[u].size();

        for(int i = 0; i < sz; ++i) {
            v = adjList[u][i];
            --indegree[v];

            if(!indegree[v]) {
                q.push(v);

                vector<int> vec(dependent[v]);
                int s = vec.size();
                int sum = 0;

                for(int i = 0; i < s; ++i)
                    sum += *(matrix+vec[i]);

                *(matrix+v) = sum;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);

    int tc;
    cin >> tc;

    while(tc--) {
        dependent.clear();
        adjList.clear();
        indegree.clear();

        int row;
        cin >> col >> row;

        matrix = new int [row*col];
        adjList.resize(row*col);
        indegree.assign(row*col, 0);

        string str;

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                cin >> str;

                if(str.front() != '=')
                    matrix(i,j) = atoi(str.c_str());
                else
                    processTheString(str, i, j);
            }
        }

        topologicalSort(row*col);

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(j) cout << ' ';
                cout << matrix(i,j);
            }
            cout << '\n';
        }

        delete [] matrix;
    }

    return 0;
}
