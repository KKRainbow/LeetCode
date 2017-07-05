/*
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges
 *
 * Medium (29.40%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
	public:
		vector<string> summaryRanges(vector<int>& nums) {
			int left = 0, right = 1;
			vector<string> res;
			stringstream ss;
			ss.clear();
			while (left < nums.size()) {
				if (right < nums.size() && nums[right] - nums[left] == right - left) {
					right++;
				} else {
					if (right - left == 1) {
						ss<<nums[left];
					} else {
						ss<<nums[left]<<"->"<<nums[right-1];  
					}
					string tmp;
					ss>>tmp;
					ss.clear();
					res.push_back(tmp);
					left = right;   
				}
			}
			return res;
		}
};
