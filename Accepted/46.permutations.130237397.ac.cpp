class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {{}};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{nums};
        while(1) {
            int pos = nums.size() - 1;
            while (nums[pos - 1] > nums[pos]) pos--;
            if (pos == 0) return res;
            reverse(nums.begin() + pos, nums.end());
            auto it = lower_bound(nums.begin() + pos, nums.end(), nums[pos - 1]);
            swap(*it, nums[pos - 1]);
            res.push_back(nums);
        }
    }
};