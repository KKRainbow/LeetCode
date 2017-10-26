class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        k = abs(k);
        unordered_map<int, list<int>> rtol; // right to left sum: indices of sum value
        vector<int> ltor(nums.size()); // left to right sum: should record sum value
        int lsum = 0, rsum = 0, prev = -1;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {
            ltor[i] = k == 0 ? lsum : lsum % k;
            rtol[k == 0 ? rsum : rsum % k].push_back(nums.size() - i);
            lsum += nums[i];
            rsum += nums[nums.size() - i - 1];
            if (prev == 0 && nums[i] == 0) flag = true;
            prev = nums[i];
        }
        if (flag) return true; // continuous 0
        if (k == 0) return false;
        sum = lsum;
        
        for (int i = 0; i < ltor.size() - 1; i++) {
            // [sum - (ltor + rtol)] % k == 0 -> (sum - ltor) % k == rtol % k
            int remain = (sum - ltor[i]) % k;
            for (auto idx : rtol[remain]) {
                if (idx - i >= 2) return true; // index space large than 2
            }
        }
        
        return false;
    }
};