class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int m = nums.size() / 2, l = 0, h = nums.size();
		while (h - l > 3) {
			if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) return nums[m];
			int delim = nums[m] == nums[m - 1] ? m - 1 : m + 2;
			if ((delim - l) % 2 == 0) {
				l = delim;
			}
			else {
				h = delim;
			}
			m = (l + h) / 2;
		}
		if (h - l == 1) return nums[l];
		else return nums[m] != nums[m - 1] ? nums[m - 1] : nums[m + 1];
	}
};
