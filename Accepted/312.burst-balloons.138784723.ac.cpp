class Solution {
    // a good helper to think
    vector<int> nums;
    map<tuple<int,int,int,int>, int> table;
    int helper(int ls, int rs, int leftScore, int rightScore) {
        auto key = make_tuple(ls, rs, leftScore, rightScore);
        auto it = table.find(key);
        if (it != table.end()) {
            return it->second;
        }
        if (ls == rs) {
            return 0;
        }
        int m = INT_MIN;
        for (int i = ls; i < rs; i++) {
            int left = helper(ls, i, leftScore, nums[i]);
            int right = helper(i + 1, rs, nums[i], rightScore);
            m = max(m, left + right + nums[i] * leftScore * rightScore);
        }
        table[key] = m;
        return m;
    }
    int maxCoinsTop2Bottom(vector<int>& nums) {
        this->nums = nums;
        return helper(0, nums.size(), 1, 1);
    }
public:
    int maxCoins(vector<int>& nums) {
        // 自底向上来一发
        vector<vector<int>> table(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        auto getScore = [&nums](int index) { 
            if (index < -1 || index > (int)nums.size()) {
                cout << index << endl;
                throw new exception();
            }
            if (index == -1) return 1;
            if (index == nums.size()) return 1;
            else return nums[index];
        };
        // table[len][startIdx]
        for (int len = 1; len <= nums.size(); len++) {
            for (int startIdx = 0; startIdx + len <= nums.size(); startIdx++) {
                int ls = startIdx, rs = startIdx + len;
                int m = INT_MIN;
                for (int i = ls; i < rs; i++) {
                    m = max(m, table[i - ls][ls] + table[rs - i - 1][i + 1] + nums[i] * getScore(ls - 1) * getScore(rs));
                }
                table[len][startIdx] = m;
            }
        }
        return table[nums.size()][0];
    }
};
