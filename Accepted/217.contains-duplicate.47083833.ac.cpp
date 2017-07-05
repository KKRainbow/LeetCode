/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate
 *
 * Easy (45.34%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * 
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 */
class Solution {
	public:
		bool containsDuplicate(vector<int>& nums) {
			unordered_map<int,bool> hash;
			for(auto i: nums)
			{
				if(hash[i] == true)return true;
				else
				{
					hash[i] = true;
				}
			}
			return false;
		}
};
