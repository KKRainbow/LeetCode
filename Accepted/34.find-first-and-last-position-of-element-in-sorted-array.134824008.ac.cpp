class Solution {
    int target;
    int lowerBound(const vector<int>& nums, int s, int e) {
        int mid = (s + e - 1) / 2;
        if (e - s == 1) {
            return s;
        }
        if (nums[mid] < target) {
            return lowerBound(nums, mid + 1, e);
        } else {
            return lowerBound(nums, s, mid + 1);
        }
    }
    int upperBound(const vector<int>& nums, int s, int e) {
        int mid = (s + e - 1) / 2;
        if (e - s == 1) {
            return nums[s] == target ? e : s;
        }
        if (nums[mid] <= target) {
            return upperBound(nums, mid + 1, e);
        } else {
            return upperBound(nums, s, mid + 1);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        this->target = target;
        int l, h;
        tie(l, h) = make_tuple(lowerBound(nums, 0, nums.size()), upperBound(nums, 0, nums.size()));
        if (nums[l] != target) {
            return {-1, -1};
        } else {
            return {l, h - 1};
        }
    }
};
