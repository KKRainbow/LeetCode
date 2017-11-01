class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n, 0);
        int sign = k % 2 == 0 ? -1 : 1;
        int base = k / 2 + 1;
        for (int i = 1; i < n; i++) {
            if (i <= k) {
                res[i] = res[i - 1] + i * sign;
            } else {
                res[i] = res[i - 1] + 1;
            }
            sign *= -1;
            res[i - 1] += base;
        }
        res[res.size() - 1] += base;
        return res;
    }
};