class Solution {
public:
    int integerReplacement(uint32_t n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n >> 1);
        } else {
            return 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
        }
    }
};