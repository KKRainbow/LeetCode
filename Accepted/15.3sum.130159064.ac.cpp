class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> hash;
        hash.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            hash.clear();
            int target = -nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int tmp = target - nums[j];
                if (binary_search(nums.begin() + j + 1, nums.end(), tmp)) {
                    res.push_back({nums[i], nums[j], target - nums[j]});      
                }
            }
        }
        return res;
    }
};