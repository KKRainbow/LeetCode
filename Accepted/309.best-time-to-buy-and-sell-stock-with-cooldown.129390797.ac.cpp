class Solution {
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
    int max4(int a, int b, int c, int d) {
        return max(a, max(b, max(c, d)));
    }
public:
    int maxProfit(vector<int>& prices) {
        // true/false: have stock in that day or not
        if (prices.empty()) return 0;
        vector<int> trueVec(prices.size(), INT_MIN), normalFalseVec(prices.size(), INT_MIN), coolDownFalseVec(prices.size() + 1, INT_MIN);
        int maxNormalFalse, maxTrue, maxCoolDownFalse;
        maxNormalFalse = normalFalseVec[0] = 0;
        maxCoolDownFalse = coolDownFalseVec[0] = INT_MIN;
        maxTrue = trueVec[0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            trueVec[i] = max3(max(coolDownFalseVec[i - 1], normalFalseVec[i - 2]) - prices[i], trueVec[i - 1], maxTrue);
            normalFalseVec[i] = max3(coolDownFalseVec[i - 1], normalFalseVec[i - 1], maxNormalFalse);
            auto tmp = trueVec[i - 1] + prices[i];
            if (tmp > normalFalseVec[i]) {
                normalFalseVec[i] = tmp;
                coolDownFalseVec[i + 1] = normalFalseVec[i];
                maxCoolDownFalse = max(coolDownFalseVec[i + 1], maxCoolDownFalse);
            }
            maxTrue = max(trueVec[i], maxTrue);
            maxNormalFalse = max(normalFalseVec[i], maxNormalFalse);        
            //cout << trueVec[i] << ' ' << normalFalseVec[i] << ' ' << coolDownFalseVec[i] << endl;
        }
        return max(normalFalseVec.back(), coolDownFalseVec.back());
    }
};