class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int mid = (s + e) / 2;
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return nums[s];
    }
};