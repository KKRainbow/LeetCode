/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum
 *
 * Easy (33.70%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,2,4]\n6'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> vec;
			vec.reserve(nums.size());
			unordered_map<int,int> map,map2;
			int idx = 0;
			for(int i = 0;i < nums.size(); i++)
			{
				vec.push_back(int(nums[i]));
				if(map.find(nums[i])== map.end())
					map[nums[i]] = i+1;
				else
					map2[nums[i]] = i+1;
			}
			sort(vec.begin(),vec.end(),less<int>());
			for(int i = vec.size() - 1;i > 0;i--)
			{
				for(int j = 0;j<i;j++)
				{
					int res = vec[i] + vec[j];
					if(res > target)
					{
						break;
					}
					else if(res == target)
					{
						int one = map[vec[j]];
						int two = map[vec[i]];
						if(one == two)
							two = map2[vec[i]];
						if(one < two)
							return vector<int>({one,two});
						else
							return vector<int>({two,one});
					}
				}
			}
			return vector<int>({0,0});

		}
};
