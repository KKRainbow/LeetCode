class Solution {
public:
    bool isPerfectSquare(int num) {
        // n^2 - (n - 1)^2 = 2n - 1
        unsigned int n = 1, cur = 0;
        while(cur <= num) {
            if (cur == num) return true;
            cur += (n << 1) - 1;
            n++;
        }
        return false;
    }
};