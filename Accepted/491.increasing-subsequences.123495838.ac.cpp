class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> ret;
        set<vector<int>> res{{nums[0]}};
        for (int i = 1; i < nums.size(); i++) {
            vector<vector<int>> tmpres;
            for (auto& s : res) {
                if (s[s.size() - 1] <= nums[i]) {
                    vector<int> tmp = s;
                    tmp.push_back(nums[i]);
                    tmpres.push_back(tmp);
                }
            }
            res.insert(vector<int>{nums[i]});
            res.insert(tmpres.begin(), tmpres.end());
        }
        for (auto& s : res) {
            if (s.size() > 1)
                ret.push_back(s);
        }
        return ret;
    }
};