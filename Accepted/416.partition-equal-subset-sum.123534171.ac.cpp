class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        
        int size = 100 * 200;
        int vec[size];
        // f(n, v) = min  f (n - 1, v), f(n - 1, v - g(n)) + c(n)
        fill(vec, vec + sizeof(vec) / sizeof(int), 0);
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= nums[i]; j--) {
                vec[j] = max(vec[j], vec[j - nums[i]] + nums[i]);
            }
        }
        return vec[sum] == sum;            
    }
};