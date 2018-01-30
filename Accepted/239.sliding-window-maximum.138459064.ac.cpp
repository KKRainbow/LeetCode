class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        multiset<int, greater<int>> s;
        int ok = k;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            s.insert(nums[i]);
        }
        while (k <= nums.size()) {
            result.push_back(*s.begin());
            if (k < nums.size()) {
                s.erase(s.find(nums[k - ok]));
                s.insert(nums[k]); 
            }
            
            k++;
        }
        return result;
    }
};