class Solution {
public:
    double myPow(double x, int m) {
        double res = 1;
        unsigned int n = m;
        if (m < 0) {
            x = 1 / x;
            n = -m;
        }
        while (n) {
            if (n & 1) {
                res *= x;
            }
            n >>= 1;
            x *= x;
        }
        return res;
    }
};