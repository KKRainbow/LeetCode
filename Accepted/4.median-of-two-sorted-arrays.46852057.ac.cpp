/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays
 *
 * Hard (21.47%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int count = nums1.size() + nums2.size();
			int total = count;
			count /= 2;
			count++;
			auto it1 = nums1.begin();
			auto it2 = nums2.begin();
			register auto* pit = &it1;
			if(*pit == nums1.end())pit = &it2;
			if(*pit == nums2.end())return 0;
			int prev,next;
			next = **pit;
			while(count--)
			{
				prev = next;
				if(it1 == nums1.end())
					pit = &it2;
				else if(it2 == nums2.end())
					pit = &it1;
				else if(*it1 <= * it2)
					pit = &it1;
				else
					pit = &it2;

				next = **pit;
				++*pit;
			}
			cout<<endl<<next<<'\t'<<prev<<' '<<(total&1)<<endl;
			if((total & 1) == 0)return (next*1.0 + prev)/2;
			else return next;
		}
};
