class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = INT_MAX, maxc = -1;
        vector<int> l(50000, INT_MAX), r(l.size()), c(l.size());
        for (int i = 0; i < nums.size(); i++) {
            l[nums[i]] = min(i, l[nums[i]]);
            r[nums[i]] = max(i, r[nums[i]]);
            if (maxc <= ++c[nums[i]]) {
                if (maxc < c[nums[i]]) {
                    res = r[nums[i]] - l[nums[i]];
                } else {
                    res = min(res, r[nums[i]] - l[nums[i]]);
                }
                maxc = c[nums[i]];
            }
        }
        return res + 1;
    }
};