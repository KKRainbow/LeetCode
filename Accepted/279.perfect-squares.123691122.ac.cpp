class Solution {
    int helper(int n) {
        int t = sqrt(n);
        int res = n;
        for (int i = 1; i <= t; i++) {
            int t = i * i;
            res = min(res, n / t + helper(n - t * (n / t)));
        }
        return res;
    }
public:
    int numSquares(int n) {
        return helper(n);
    }
};