class Solution {
    // DP 解法：
    // [Start， End]区间内，Player 1/2能获得的max/min分数，一方获得max分数则另一方获得min分数
    // 结果可以总结为 [0, nums.size()]区间内，player1先出手时获得的max分数大于player2后出手时的max分数
    vector<int> nums;
    // 此为递归解法，pair中存放player1 player2的max分数，自顶向下不带优化的DP
    pair<int, int> helper(int start, int end, bool isFirst) {
        if (end == start) {
            return {0, 0};
        }
        auto a = helper(start + 1, end, !isFirst);
        auto b = helper(start, end - 1, !isFirst);
        auto h = nums[start], t = nums[end - 1];
        int sum = accumulate(nums.begin() + start, nums.begin() + end, 0);
        if (isFirst) {
            auto tmp1 = max(h + a.first, t + b.first);
            return { tmp1, sum - tmp1 };
        } else {
            auto tmp1 = max(h + a.second, t + b.second);
            return {sum - tmp1, tmp1};
        }
    }
    // 此为DP解法
    bool dp(vector<int>& nums) {
        vector<pair<int, int>> table(nums.size() + 1);
        bool isFirst = nums.size() % 2 == 1;
        for (int len = 1; len <= nums.size(); len++) {
            for (int start = 0; start + len <= nums.size(); start++) {
                auto &b = table[start];
                auto &a = table[start + 1];
                auto h = nums[start], t = nums[start + len - 1];
                int sum = accumulate(nums.begin() + start, nums.begin() + start + len, 0);
                if (isFirst) {
                    auto tmp1 = max(h + a.first, t + b.first);
                    table[start] = { tmp1, sum - tmp1 };
                } else {
                    auto tmp1 = max(h + a.second, t + b.second);
                    table[start] = {sum - tmp1, tmp1};
                }
            }
            isFirst = !isFirst;
        }
        return table[0].first >= table[0].second;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        this->nums = nums;
        //auto tmp = helper(0, nums.size(), true);
        //return tmp.first >= tmp.second;
        return dp(nums);
    }
};
