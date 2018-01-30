class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int s = 0, e = nums.size();
        k--;
        while (e >= s) {
            swap(nums[s], nums[s + (rand() % (e - s))]);
            auto l = s + 1, g = e;
            while (l != g) {
                if (nums[l] < nums[s]) {
                    g--;
                    swap(nums[l], nums[g]);
                } else {
                    l++;
                }
            }
            swap(nums[l - 1], nums[s]);
            if (l - 1 - s == k) {
                return nums[l - 1];
            } else if (l - 1 - s > k) {
                e = l - 1;
            } else {
                k -= l - s;
                s = l;
            }
        }
        return nums[s];
    }
};