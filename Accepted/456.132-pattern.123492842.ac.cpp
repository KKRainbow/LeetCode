class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        multiset<int> ms(nums.begin(), nums.end());
        int left_min = INT_MAX;
        for (auto m : nums) {
            auto it = ms.find(m);
            auto tmpit = it;
            auto second_small = it == ms.begin() ? INT_MIN : *(--it);
            ms.erase(tmpit);
            if (second_small > left_min) {
                return true;
            }
            left_min = min(left_min, m);
        }
        return false;
    }
};