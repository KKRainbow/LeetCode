class Solution {
    int findMinIdx(const vector<int>& nums, int s, int e) {
        int mid = (s + e - 1) / 2;
        if (e - s == 1) {
            return s;
        }
        if (nums[mid] <= nums[e - 1]) {
            return findMinIdx(nums, s, mid + 1);
        } else {
            return findMinIdx(nums, mid + 1, e);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int minIdx = findMinIdx(nums, 0, nums.size());
        vector<int>::iterator tIter = nums.end();
        //cout << minIdx << endl;
        if (nums.back() >= target) {
            tIter = lower_bound(nums.begin() + minIdx, nums.end(), target);
        } else {
            tIter = lower_bound(nums.begin(), nums.begin() + minIdx, target);
        }
        if (tIter != nums.end() && *tIter == target) {
            return tIter - nums.begin();
        } else {
            return -1;
        }
    }
};