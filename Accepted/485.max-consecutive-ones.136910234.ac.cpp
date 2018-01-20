class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, curCount = 0;
        for (auto i: nums) {
            curCount = i ? curCount + 1 : 0;
            count = max(count, curCount);
        }
        return count;
    }
};