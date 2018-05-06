class NumArray {
    vector<int> bit;
    vector<int> nums;
public:
    void update(int idx, int val) {
        int diff = val - nums[idx];
        int step = idx + 1;
        while (step <= nums.size()) {
            bit[step] += diff;
            step += step & (-step);
        }
        nums[idx] += diff;
    }

    NumArray(vector<int> nums) {
        bit.resize(nums.size() + 1);
        this->nums = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }

    int getSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
