class Solution {
    vector<int> origin;
public:
    Solution(vector<int> nums) {
        origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto res = origin;
        for (int i = 0; i < res.size(); i++) {
            swap(res[i], res[i + (rand() % (res.size() - i))]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
