class Solution {
public:
    int trailingZeroes(int n) {
        uint64_t x = 5;
        int res = 0;
        while (n >= x) {
            res += n / x;
            x *= 5;
        }
        return res;
    }
};
