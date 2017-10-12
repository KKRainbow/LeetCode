class Solution {
public:
    void sortColors(vector<int>& nums) {
        int b = 0, e = nums.size(), m = 0;
        while (m < e) {
            if (m < b) {
                m++;
                continue;
            }
            switch (nums[m]) {
                case 0:
                    swap(nums[b], nums[m]);
                    b++;
                    break;
                case 1:
                    m++;
                    break;
                case 2:
                    swap(nums[e - 1], nums[m]);
                    e--;
                    break;
            }
        }
    }
};