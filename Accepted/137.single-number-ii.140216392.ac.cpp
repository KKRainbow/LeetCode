class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> tmp(sizeof(int) * 8, 0);
        for (auto num : nums) {
            auto n = (uint32_t)num;
            for (int i = 0; i < sizeof(n) * 8; i++) {
                auto t = n >> i;
                tmp[i] += t & 1;
                tmp[i] %= 3;
            }
        }
        uint32_t result = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            result <<= 1;
            result |= tmp[tmp.size() - i - 1];
        }
        return result;
    }
};
