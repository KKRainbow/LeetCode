class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void helper(const vector<int>& vec, int index, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (index >= vec.size()) return;
        int t = 0, maxt = 0;
        while (index + maxt < vec.size() && vec[index + maxt] == vec[index + t]) {
            maxt++;
        }
        auto e = cur.size();
        for (; t <= maxt && vec[index] * t <= target; t++) {
            helper(vec, index + maxt, target - t * vec[index]);
            cur.push_back(vec[index]);
        }
        cur.erase(cur.begin() + e, cur.begin() + e + t);
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        cur.clear();
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return res;
    }
};