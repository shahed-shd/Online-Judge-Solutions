// ==================================================
// Problem  :   836 - Rectangle Overlap
// Run time :   0.000 sec
// Language :   C++11
// ==================================================


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return isLineOperlap(rec1[0], rec1[2], rec2[0], rec2[2]) && isLineOperlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    }

    bool isLineOperlap(int a, int b, int c, int d) {
        if (a == b || c == d || d <= a || b <= c) return false;
        return true;
    }
};
