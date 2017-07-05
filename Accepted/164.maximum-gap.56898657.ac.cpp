/*
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap
 *
 * Hard (29.32%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Try to solve it in linear time/space.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * 
 * Credits:Special thanks to @porker2008 for adding this problem and creating
 * all test cases.
 */
int maximumGap(int* nums, int numsSize) {
	if (numsSize < 2) {
		return 0;
	}
	int nmin = INT_MAX, nmax = INT_MIN;
	for (int i = 0 ; i < numsSize; i++) {
		if (nmin > nums[i]) {
			nmin = nums[i];
		}
		if (nmax < nums[i]) {
			nmax = nums[i];
		}
	}
	if (nmin == nmax || numsSize == 2) {
		return nmax - nmin;
	}

	int aveGap = (nmax - nmin) / (numsSize - 1) + 1;

	int** bucket = (int**)calloc(numsSize, sizeof(int**));

	for (int i = 0; i < numsSize; i++) {
		bucket[i] = (int*)calloc(2, sizeof(int));
		bucket[i][0] = INT_MAX;
		bucket[i][1] = INT_MIN;
	}

	for (int i = 0; i < numsSize; i++) {
		int idx = (nums[i] - nmin) / aveGap;
		bucket[idx][0] = min(bucket[idx][0], nums[i]);
		bucket[idx][1] = max(bucket[idx][1], nums[i]);
	}

	int res = 0;
	int left = 0, right = 1;
	for (left = 0; left < numsSize;) {
		right = left + 1;
		while (right < numsSize && bucket[right][1] == INT_MIN) {
			right++;
		}
		if (right < numsSize) {
			res = max (res, bucket[right][0] - bucket[left][1]);
		}
		left = right;
	}
	return res;
}
class Solution {
	public:
		int maximumGap(vector<int>& nums) {
			return ::maximumGap(&nums[0], nums.size());
		}
};
