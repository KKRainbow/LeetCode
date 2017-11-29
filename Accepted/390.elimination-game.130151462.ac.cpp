class Solution {
public:
    int lastRemaining(int n) {
        int res = 1;
        int inteval = 1;
        while (n > 1) {
            res += inteval;
            inteval *= 2;
            n /= 2;
            if (n <= 1) break;
            if (n % 2 != 0) {
                res += inteval;
            }
            n /= 2;
            inteval *= 2;
        }
        return res;
    }
};