class Solution {
public:
    int reverse(int x) {
        if (!x) return 0;
        int sign = x / abs(x);
        x = abs(x);
        uint64_t res = 0;
        while (x) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        if (res > INT_MAX) return 0;
        else return res * sign;
    }
};