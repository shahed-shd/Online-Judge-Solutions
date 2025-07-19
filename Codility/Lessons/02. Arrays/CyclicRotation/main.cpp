// ==================================================
// Problem  :   CyclicRotation
// Score    :   100
// Language :   C++17
// ==================================================


vector<int> solution(vector<int> &A, int K) {
    if (A.empty()) return A;

    int sz = A.size();
    int shiftCount = K % sz;

    if (shiftCount == 0) return A;

    vector<int> shifted(sz);

    for (int i = 0; i < sz; ++i) {
        shifted[(i + shiftCount) % sz] = A[i];
    }

    return shifted;
}
