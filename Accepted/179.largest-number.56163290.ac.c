/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number
 *
 * Medium (22.36%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */

int cmp(const void* l, const void* r)
{
	const char* a = (const char*)*(const char**)l;
	const char* b = (const char*)*(const char**)r;

	int len = strlen(a) + strlen(b);
	char* tmp = (char*)calloc(len + 1, sizeof(char));
	char* tmp1 = (char*)calloc(len + 1, sizeof(char));

	strcat(tmp, a);
	strcat(tmp, b);
	strcat(tmp1, b);
	strcat(tmp1, a);

	int res = strcmp(tmp1, tmp);

	free(tmp);
	free(tmp1);

	return res;
}

char* largestNumber(int* nums, int numsSize) {
	char** strs = (char**)calloc(numsSize, sizeof(char*));
	int len = 0;
	int flag = 0;

	for (int i = 0; i < numsSize; i++) {
		int t = nums[i], idx = t > 0 ? (int)log10(t) + 1 : 1;
		if (t != 0) {
			flag = 1;
		}
		strs[i] = (char*)calloc(idx + 1, sizeof(char));
		len += idx;
		while (idx--) {
			strs[i][idx] = '0' + (t % 10);
			t /= 10;
		}
	}

	if (!flag) {
		return "0";
	}

	qsort(strs, numsSize, sizeof(char*), cmp);
	char* res = (char*)calloc(len + 2, sizeof(char));
	for (int i = 0; i < numsSize; i++) {
		strcat(res, strs[i]);
		free(strs[i]);
	}
	free(strs);
	return res;
}
