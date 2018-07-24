class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int curDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                auto begIt = nums.begin() + j + 1;
                auto remain = target - nums[i] - nums[j];
                auto it = lower_bound(begIt, nums.end(), remain);
                if (it != nums.end() && abs(*(it) - remain) < abs(curDiff)) {
                    curDiff = -(*(it) - remain);
                }
                if (it != begIt && abs(*(it - 1) - remain) < abs(curDiff)) {
                    curDiff = -(*(it - 1) - remain);
                }
                if (curDiff == 0) return target;
            }
        }
        return target - curDiff;
    }
};
