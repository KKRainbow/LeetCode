class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size() - 2;
        for (; idx >= 0; idx--) {
            if (nums[idx] >= nums[idx + 1]) continue;
            reverse(nums.begin() + idx + 1, nums.end());
            auto iter = upper_bound(nums.begin() + idx + 1, nums.end(), nums[idx]);
            swap(*iter, nums[idx]);
            break;
        }
        if (idx < 0) {
            reverse(nums.begin(), nums.end());
        }
    }
};