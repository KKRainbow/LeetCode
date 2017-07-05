/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence
 *
 * Medium (38.14%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * 
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length
 * is 4. Note that there may be more than one LIS combination, it is only
 * necessary for you to return the length.
 * 
 * 
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity? 
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			if (nums.size() == 0)
				return 0;
			map<int, int> table;
			int res_max = 1;
			for (auto num : nums)
			{
				auto iter = table.upper_bound(num);
				//smallest is larger than num
				if (iter == table.begin())
				{
					cout << iter->first;
					table[num] = 1;
				}
				else
				{
					advance(iter, -1);
					int cur_len = 0;
					if (num == iter->first)
					{
						auto tmp = iter;
						--tmp;
						if (tmp->first < num)
						{
							cur_len = tmp->second + 1;
						}
						else
						{
							cur_len = iter->second;
						}
					}
					else
					{
						cur_len = iter->second + 1;
					}
					while (++iter != table.end())
					{
						iter->second = max(iter->second, cur_len);
					}
					table[num] = cur_len;
					if (res_max < cur_len)
					{
						res_max = cur_len;
					}
				}
			}
			return res_max;
		}
};
