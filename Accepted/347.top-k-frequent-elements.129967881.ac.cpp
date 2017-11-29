class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>> q;
        nums.push_back(nums.back() - 1);
        int prev = nums[0], prevc = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                q.push(make_pair(prevc, prev));
                prev = nums[i];
                prevc = 1;
            } else {
                prevc++;
            }
        }
        vector<int> res;
        while (k-- && !q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};