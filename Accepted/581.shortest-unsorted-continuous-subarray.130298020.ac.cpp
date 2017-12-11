class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minIdx = nums.size(), maxIdx = nums.size();
        int minVal = nums[0], tmpIdx = 0, maxVal = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            auto tmp = nums[i];
            if (tmp < maxVal) {
                maxIdx = i + 1;
            } else {
                maxVal = nums[i];
            }
            if (tmp < minVal) {
                tmpIdx = upper_bound(nums.begin(), nums.begin() + tmpIdx, tmp) - nums.begin();
                minVal = tmp;
                minIdx = tmpIdx;
            } else if (minIdx == nums.size()) {
                tmpIdx++;
                minVal = nums[tmpIdx];
            }
        }
        
        return maxIdx - minIdx;
    }
};