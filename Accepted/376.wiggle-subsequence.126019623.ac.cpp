class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        int a1 = 1, a2 = 1, res1 = 1, res2 = 1;
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i] - nums[i - 1];
            if (x * a1 > 0) {
                a1 *= -1;
                res1 += 1;
            }
            if (x * a2 < 0) {
                a2 *= -1;
                res2 += 1;
            }
        }
        return max(res1, res2);
    }
};