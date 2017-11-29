class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    int k;
    void helper(const vector<int>& vec, int index, int target) {
        if (cur.size() > k) return;
        if (target == 0) {
            if (cur.size() != k) return;
            res.push_back(cur);
            return;
        }
        if (index >= vec.size()) return;
        int t = 0;
        auto e = cur.size();
        for (; t <= 1 && vec[index] * t <= target; t++) {
            helper(vec, index + 1, target - t * vec[index]);
            cur.push_back(vec[index]);
        }
        cur.erase(cur.begin() + e, cur.begin() + e + t);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        res.clear();
        cur.clear();
        helper({1,2,3,4,5,6,7,8,9}, 0, n);
        return res;
    }
};