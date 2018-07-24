class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int size = nums.size();
        for (auto& n : nums) {
            n = n % size == 0 ? size * 2 : n % size;
        }
        for (int i = 0; i < size; i++) {
            int sum = 0;
            int j = i;
            bool firstTime = true;
            while (abs(nums[j] / size) <= 1) {
                if (abs(nums[j] / size) == 1 && firstTime) {
                    sum = 0;
                    firstTime = false;
                }
                if (sum * nums[j] < 0) {
                    sum = nums[j];
                } else {
                    sum += nums[j];
                }
                nums[j] += (nums[j] / abs(nums[j])) * size;
                j = (size + (j + nums[j]) % size) % size;
            }
            if (sum != 0 && sum % size  == 0) {
                return true;
            }
        }
        return false;
    }
};
