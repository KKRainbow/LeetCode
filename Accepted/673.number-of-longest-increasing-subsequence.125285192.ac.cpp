class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxLen = 0, count = 0;
        vector<int> lenArr(nums.size(), INT_MAX);
        vector<map<int, int>> lenMapArr(nums.size());
        for (auto n : nums) {
            auto pos = lower_bound(lenArr.begin(), lenArr.begin() + maxLen, n) - lenArr.begin();
            if (pos == maxLen) {
                maxLen++;
            }
            lenArr[pos] = min(n, lenArr[pos]);
            if (pos > 0) {
                for (auto& p: lenMapArr[pos - 1]) {
                    if (p.first >= n) break;
                    else lenMapArr[pos][n] += p.second;
                }            
            }
            else {
                lenMapArr[pos][n]++;
            }
        }
        if (maxLen == 0) return 0;
        for (auto& p : lenMapArr[maxLen - 1]) {
            count += p.second;
        }
        return count;
    }
};