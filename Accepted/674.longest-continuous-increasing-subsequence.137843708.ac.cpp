class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1, result = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
                result = max(result, count);
            } else {
                count = 1;
            }
        }
        return max(result, count);
    }
};