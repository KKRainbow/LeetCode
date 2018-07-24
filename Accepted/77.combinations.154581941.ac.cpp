class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int>& inter, int n, int k)
    {
            if (n < k) {
                    return;
            }
            if (k == 0) {
                    result.push_back(inter);
                    return;
            }
            helper(result, inter, n - 1, k);
            inter.push_back(n);
            helper(result, inter, n - 1, k - 1);
            inter.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> inter;
        helper(result, inter, n, k);
        return result;
    }
};
