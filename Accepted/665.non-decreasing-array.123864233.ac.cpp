class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i = 1;
        nums.push_back(INT_MAX);
        nums.insert(nums.begin(), INT_MIN);
        while (i < nums.size() && nums[i] >= nums[i - 1]) i++;
        if (i == nums.size()) return true;
        if (nums[i] >= nums[i - 2]) i += 1;
        else if (nums[i + 1] >= nums[i - 1]) i += 2;
        while (i < nums.size() && nums[i] >= nums[i - 1]) i++;
        if (i == nums.size()) return true;
        return false;
    }
};