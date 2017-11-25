class Solution {
    int target;
    bitset<16> mask;
    bool checkArray(const vector<int>& arr, int k, int curTarget, int curI) {
        if (k > arr.size()) {
            return false;
        }
        if (k == 0 && mask.count() == arr.size() && curTarget == target) {
            return true;
        }
        auto idx = lower_bound(arr.begin(), arr.end(), curTarget) - arr.begin();
        int lower = idx;
        while (idx != arr.size() && arr[idx] == curTarget && mask[idx] == 1) idx++;
        if (idx < arr.size() && arr[idx] == curTarget) {
            mask[idx] = 1;
            if (checkArray(arr, k - 1, target, 0)) {
                return true;
            }
            mask[idx] = 0;
        } else {
            for (int i = curI; i < lower; i++) {
                if (mask[i]) continue;
                mask[i] = 1;
                if (checkArray(arr, k, curTarget - arr[i], i + 1)) {
                    return true;
                }
                mask[i] = 0;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        target = sum / k;
        sort(nums.begin(), nums.end());
        mask.reset();
        return checkArray(nums, k, target, 0);
    }
};