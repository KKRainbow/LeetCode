/*
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number
 *
 * Hard (24.38%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * 
 * ⁠   Given two arrays of length m and n with digits 0-9 representing two
 * numbers.
 * ⁠   Create the maximum number of length k <= m + n from digits of the two.
 * The relative order of the digits
 * ⁠   from the same array must be preserved. Return an array of the k digits.
 * You should try to optimize your time and space complexity.
 * 
 * 
 * 
 * ⁠   Example 1:
 * 
 * 
 * ⁠   nums1 = [3, 4, 6, 5]
 * ⁠   nums2 = [9, 1, 2, 5, 8, 3]
 * ⁠   k = 5
 * ⁠   return [9, 8, 6, 5, 3]
 * 
 * 
 * ⁠   Example 2:
 * 
 * 
 * ⁠   nums1 = [6, 7]
 * ⁠   nums2 = [6, 0, 4]
 * ⁠   k = 5
 * ⁠   return [6, 7, 6, 0, 4]
 * 
 * 
 * ⁠   Example 3:
 * 
 * 
 * ⁠   nums1 = [3, 9]
 * ⁠   nums2 = [8, 9]
 * ⁠   k = 3
 * ⁠   return [9, 8, 9]
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
#include <malloc.h>
#include <string.h>

struct array {
	int* arr;
	int* subarr;
	int size;
	int cutpos;
	int currSubSize;
};

struct array getArray(int* nums, int numsSize)
{
	struct array a =  (struct array) {
		nums,
			(int*)malloc((numsSize + 1) * sizeof(*nums)),
			numsSize,
			0,
			numsSize
	};
	memcpy(a.subarr, a.arr, numsSize * sizeof(int));
	a.subarr[numsSize] = -1;
	return a;
}

void cutArray(struct array* arr)
{
	if (arr->currSubSize == 0) {
		return;
	}
	//cutpos 之前都是递减
	for (; arr->cutpos < arr->currSubSize; arr->cutpos++) {
		if (arr->cutpos >= arr->currSubSize - 1) {
			break;
		} else if (arr->subarr[arr->cutpos] < arr->subarr[arr->cutpos + 1] ) {
			memmove(arr->subarr + arr->cutpos,
					arr->subarr + arr->cutpos + 1,
					((size_t)(arr->currSubSize - arr->cutpos - 1)) * sizeof(*arr->subarr)
				   );
			break;
		}
	}
	arr->currSubSize--;
	arr->subarr[arr->currSubSize] = -1;
	if (arr->cutpos > 0) {
		arr->cutpos--;
	}
}

int* merge(int* a1, int a1Size, struct array* a2, int k)
{
	int* str = (int*)malloc((k + 1) * sizeof(*str));
	int left = 0, right = 0;
	for (int i = 0; i < k; i++)
	{
		//数组末尾是-1，比其他数都小
		if (a1[left] == a2->subarr[right]) {
			int lcursor = left + 1, rcursor = right + 1, tmp = a1[left];
			while (a1[lcursor] == a2->subarr[rcursor]) {
				lcursor++, rcursor++;
			}
			if (a1[lcursor] > a2->subarr[rcursor]) {
				str[i] = a1[left++];
			} else {
				str[i] = a2->subarr[right++];
			}
		} else {
			str[i] = a1[left] > a2->subarr[right] ? a1[left++] : a2->subarr[right++];
		}

	}
	return str;
}

int isLeftGreterThanRight(int* left, int* right, int k)
{
	for (int i = 0; i < k; i++) {
		if (left[i] > right[i]) {
			return 1;
		} else if (left[i] < right[i]){
			return 0;
		}
	}
	//相等返回0
	return 0;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
	if (!nums1Size && !nums2Size) {
		*returnSize = 1;
		return (int*)malloc(sizeof(int));
	}

	//让a1长度比a2小
	if (nums2Size < nums1Size) {
		int* tmp;
		tmp = nums2;
		nums2 = nums1;
		nums1 = tmp;
		int tmp2;
		tmp2 = nums2Size;
		nums2Size = nums1Size;
		nums1Size = tmp2;
	}

	struct array a1,a2;
	a1 = getArray(nums1, nums1Size);
	a2 = getArray(nums2, nums2Size);
	int *res = NULL;
	*returnSize = k;

	if (!nums1Size) {
		while (a2.currSubSize > k) {
			cutArray(&a1);
		}
		res = (int*) malloc(sizeof(int) * k);
		memcpy(res, a2.subarr, sizeof(int) * k);
		return res;
	}

	int c = a1.size > k ? k : a1.size;
	int** a1Cache = (int**)malloc(sizeof(*a1Cache) * c);
	while (a1.currSubSize > c) {
		cutArray(&a1);
	}
	a1Cache[c - 1] = (int*)malloc(sizeof(**a1Cache) * (a1.currSubSize + 1));
	memcpy(a1Cache[c - 1], a1.subarr, sizeof(*a1.subarr) * (a1.currSubSize + 1));
	for (int i = c - 2; i >= 0; i--) {
		cutArray(&a1);
		a1Cache[i] = (int*)malloc(sizeof(**a1Cache) * (a1.currSubSize + 1));
		memcpy(a1Cache[i], a1.subarr, sizeof(*a1.subarr) * (a1.currSubSize + 1));
	}

	for (int i = 1; i <= c; i++) {
		int a2Size = k - i;
		if (a2Size > a2.size) {
			continue;
		}
		while (a2.currSubSize > a2Size) {
			cutArray(&a2);
		}

		int* tmp = merge(a1Cache[i - 1], i, &a2, k);
		if (!res || isLeftGreterThanRight(tmp, res, k)) {
			if (!res) {
				free(res);
			}
			res = tmp;
		} else {
			free(tmp);
		}
	}
	return res;
}
