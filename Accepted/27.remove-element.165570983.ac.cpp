class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int tail = 0, cursor = 0;
        while (cursor < nums.size()) {
            if (nums[cursor] != val) {
                nums[tail] = nums[cursor];
                tail++;
            }
            cursor++;
        }
        return tail;
    }
};
