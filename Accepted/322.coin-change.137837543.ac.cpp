class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int count = 0;;count = (count == 0 ? 1 : count * 2)) {
                auto value = count * coins[i];
                if (value > amount) {
                    break;
                }
                for (int w = amount; w >= value; w--) {
                    int include = -1;
                    int exclude = dp[w];
                    if (dp[w - value] >= 0) {
                        include = dp[w - value] + count;
                    }
                    if (exclude < 0) {
                        dp[w] = include;
                    } else if (include < 0) {
                        dp[w] = exclude;
                    } else {
                        dp[w] = min(include, exclude);
                    }
                }
            }
        }
        return dp[amount];
    }
};