class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        double res = (double)x / 2;
        while (true) {
            double next = (res * res + x) / (2 * res);
            if (abs(next - res) < 1) {
                return floor(next);
            }
            res = next;
        }
        return 0;
    }
};
