class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // true/false: have stock in that day or not
        if (prices.empty()) return 0;
        int maxFalse, maxTrue;
        maxFalse = 0;
        maxTrue = -prices[0] - fee;
        for (int i = 1; i < prices.size(); i++) {
            maxTrue = max(maxFalse - fee - prices[i], maxTrue);
            maxFalse = max(maxTrue + prices[i], maxFalse);
            // 根据下面brute force的实现，观察到其实falseVec和trueVec是递增的
            /*
            for (int j = 0; j < i; j++) {
                trueVec[i] = max(trueVec[i], trueVec[j]);
                trueVec[i] = max(trueVec[i], falseVec[j] - fee - prices[i]);
                falseVec[i] = max(falseVec[i], falseVec[j]);
                falseVec[i] = max(falseVec[i], trueVec[j] + prices[i]);
            }
            */
        }
        return maxFalse;
    }
};