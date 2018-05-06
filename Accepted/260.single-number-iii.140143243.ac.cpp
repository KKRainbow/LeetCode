class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
            return a ^ b;
        });
        int lastSet = (diff & (-diff));
        vector<int> res = {0, 0};
        for (auto n : nums) {
            if (n & lastSet) {
                res[0] ^= n;
            } else {
                res[1] ^= n;
            }
        }
        return res;
    }
};
