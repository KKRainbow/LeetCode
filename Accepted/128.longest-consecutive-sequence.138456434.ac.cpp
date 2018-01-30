class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, int> table;
        int res = 1;
        for (auto n : nums) {
            if (table[n] != 0) {
                continue;
            }
            auto m1 = table[n - 1];
            auto p1 = table[n + 1];
            auto len = m1 + p1 + 1;
            table[n] = table[n - m1] = table[n + p1] = len;
            res = max(len, res);
        }
        return res;
    }
};