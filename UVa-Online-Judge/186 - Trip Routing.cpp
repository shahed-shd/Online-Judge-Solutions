#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

const int MAXN = 100;
const int INF = INT_MAX/2;

vector<string> idx_city;
unordered_map<string, int> city_idx;

int mat_dist[MAXN][MAXN], nxt[MAXN][MAXN];
string mat_route[MAXN][MAXN];

void print_output(string str1, string str2)
{
    cout << "\n\nFrom                 To                   Route      Miles\n"
        << "-------------------- -------------------- ---------- -----\n";

    int start = city_idx[str1], dest = city_idx[str2], s1, s2;

    while(start != dest) {
        s1 = start;
        s2 = start = nxt[start][dest];

        cout << setw(21) << left << idx_city[s1]
            << setw(21) << idx_city[s2]
            << setw(11) << mat_route[s1][s2]
            << setw(5) << right << mat_dist[s1][s2] << '\n';
    }

    cout << setw(58+1) << "-----\n"    // 21+21+11+5 = 58
        << setw(42) << "" << "Total"
        << setw(11) << mat_dist[city_idx[str1]][dest] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    fill_n(&mat_dist[0][0], MAXN*MAXN, INF);

    string str;

    while(cin.peek() != '\n') {
        int u, v, dist;

        getline(cin, str, ',');

        if(city_idx.find(str) == city_idx.end())
            idx_city.push_back(str), city_idx[str] = idx_city.size()-1;

        u = city_idx[str];

        getline(cin, str, ',');

        if(city_idx.find(str) == city_idx.end())
            idx_city.push_back(str), city_idx[str] = idx_city.size()-1;

        v = city_idx[str];

        getline(cin, str, ',');

        cin >> dist;
        cin.ignore(1, '\n');

        if(dist < mat_dist[u][v]) {
            mat_dist[u][v] = mat_dist[v][u] = dist;
            mat_route[u][v] = mat_route[v][u] = str;
            nxt[u][v] = v;
            nxt[v][u] = u;
        }
    }

    int N = idx_city.size();

    for(int k = 0; k < N; ++k)         // Floyd-Warshall.
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                if(mat_dist[i][j] > mat_dist[i][k] + mat_dist[k][j]) {
                    mat_dist[i][j] = mat_dist[i][k] + mat_dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }

    cin.ignore(1, '\n');

    string str2;

    while(getline(cin, str, ',')) {
        getline(cin, str2);
        print_output(str, str2);
    }

    return 0;
}
