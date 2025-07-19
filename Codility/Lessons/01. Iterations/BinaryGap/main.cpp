// ==================================================
// Problem  :   BinaryGap
// Score    :   100
// Language :   C++17
// ==================================================


int solution(int N) {

    while((N & 1) == 0) {
        N >>= 1;
    }

    int maxGap = 0;
    int currGap = 0;

    while(N) {
        if (N & 1) {
            maxGap = max(maxGap, currGap);
            currGap = 0;
        } else {
            ++currGap;
        }

        N >>= 1;
    }

    return maxGap;
}
