class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int b = 0, e = nums.size(), m;
        while (b != e) {
            m = (b + e) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) b = m + 1;
            else e = m;
        }
        return b;
    }
};