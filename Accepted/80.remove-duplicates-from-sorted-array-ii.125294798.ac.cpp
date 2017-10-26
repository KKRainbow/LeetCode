class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertPos = 0;
        for (int i = 1; i <= nums.size();) {
            if (i < nums.size() && nums[i] == nums[i - 1]) {
                while (nums[i] == nums[i - 1]) i++;
                nums[insertPos++] = nums[i - 1];
                nums[insertPos++] = nums[i - 1];
                i++;
            } else {
                nums[insertPos++] = nums[i - 1];
                i++;
            }
        }
        return insertPos;
    }
};