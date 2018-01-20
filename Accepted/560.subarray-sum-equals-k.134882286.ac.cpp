class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> lacc(nums.size() + 1, 0), racc(nums.size() + 1, 0);
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            lacc[i] = lacc[i - 1] + nums[i - 1];
            racc[i] = racc[i - 1] + nums[nums.size() - i];
            sum += nums[i - 1];
        }
        int count = 0;
        for (int len = 1; len <= nums.size(); len++) {
            for (int start = 0; start + len <= nums.size(); start++) {
                int tmp = sum - lacc[start] - racc[nums.size() - (start + len)];
                if (tmp == k) {
                    count++;
                }
            }
        }
        return count;
    }
};