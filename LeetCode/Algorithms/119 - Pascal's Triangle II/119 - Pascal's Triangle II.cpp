// ==================================================
// Problem  :   119 - Pascal's Triangle II
// Run time :   0.000 sec
// Language :   C++11
// ==================================================


typedef     long long       LL;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row{1};
        int n = rowIndex;

        for (int r = 1 ; r <= n; ++r) {
            row.push_back(row.back() * LL(n + 1 - r) / r);
        }
        
        return row;
    }
};
