class Solution {
public:
    void sortColors(vector<int>& nums) {
        int head = 0, tail = nums.size();
        int step = 0;
        while (step != tail) {
            if (nums[step] == 0) {
                swap(nums[step], nums[head]);
                head++;
                step = max(step, head);
            } else if (nums[step] == 2) {
                swap(nums[tail - 1], nums[step]);
                tail--;
            } else {
                step++;
            }
        }
    }
};
