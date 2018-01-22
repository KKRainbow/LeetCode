class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX;
        int start = 0, end = 1, cur = 0;
        for (;end <= nums.size(); end++) {
            cur += nums[end - 1];
            while (cur - nums[start] >= s) {
                cur -= nums[start++];
            }
            if (cur >= s)
                result = min(result, end - start);
        }
        if (cur < s || s <= 0) {
            return 0;
        }
        return result;
    }
};