class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int pos = upper_bound(nums.begin() + i + 1, nums.end(), nums[i], greater<int>()) - nums.begin();
            int tmp = nums[i];
            copy(nums.begin() + i + 1, nums.begin() + pos, nums.begin() + i);
            nums[pos - 1] = tmp;
            result[i] = nums.size() - pos;
        }
        return result;
    }
};