class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int nr = nums.size(), nc;
        if (nr != 0) nc = nums[0].size();
        if (nr == 0 || nc == 0 || r * c != nr * nc) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r * c; i++) {
            res[i / c][i % c] = nums[i / nc][i % nc];
        }
        return res;
    }
};