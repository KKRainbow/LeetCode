class Solution {
    // base, target -> count
    map<pair<int, int>, int> cache;
    vector<int> nums;
    
    int targetCount(int base, int target) {
        if (base >= nums.size()) {
            return target == 0 ? 1 : 0;
        }
        try {
            return cache.at(make_pair(base, target));
        } catch(...) {
            int res = targetCount(base + 1, target + nums[base]) + targetCount(base + 1, target - nums[base]);
            cache[make_pair(base, target)] = res;
            return res;
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        cache.clear();
        this->nums = move(nums);
        return targetCount(0, S);
    }
};