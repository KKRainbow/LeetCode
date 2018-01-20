class Solution {
    // includeLeft, maxSum, includeRight, sum
    tuple<int, int, int, int> helper(vector<int>& nums, int start, int end) {
        if (end - start == 0) {
            return make_tuple(0, 0, 0, 0);
        }
        if (end - start == 1) {
            return make_tuple(nums[start], nums[start], nums[start], nums[start]);
        }
        int mid = (start + end) / 2;
        auto l = helper(nums, start, mid);
        auto r = helper(nums, mid, end);
        
        return make_tuple(
            max(get<0>(l), get<3>(l) + get<0>(r)),
            max(max(get<1>(l), get<1>(r)), get<2>(l) + get<0>(r)),
            max(get<2>(r), get<3>(r) + get<2>(l)),
            get<3>(l) + get<3>(r)
        );
    }
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return get<1>(helper(nums, 0, nums.size()));
    }
};