class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            auto& tmp = nums[abs(nums[i]) - 1];
            if (tmp < 0) {
                return abs(nums[i]);
            } else {
                tmp = -tmp;
            }
        }
        return 0;
    }
};