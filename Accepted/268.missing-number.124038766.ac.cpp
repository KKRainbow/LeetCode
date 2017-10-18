class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0; 
        for (auto i : nums) {
            sum += i;
        }
        return (nums.size() * (nums.size() + 1)) / 2 - sum;
    }
};