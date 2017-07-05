/*
 * [135] Candy
 *
 * https://leetcode.com/problems/candy
 *
 * Hard (24.52%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[0]'
 *
 * 
 * There are N children standing in a line. Each child is assigned a rating
 * value. 
 * 
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 */
#include<cmath>
class Solution {
	public:
		static inline int get_sum(int a1, int n)
		{
			return (n*(a1 + (a1 + n - 1))) / 2;
		}
		static inline int partial_process(vector<int>& ratings, int index, int& base, int& sum)
		{
			int inc = 0, dec = 0;
			int max = 0;
			if (index == ratings.size() - 1)
			{
				sum += base + 1;
				return -1;
			}

			//连续相等情况[5,1,1,1]，可以忽略base
			if (index == 0 || ratings[index - 1] == ratings[index])
			{
				base = 0;
			}

			if (ratings[index + 1] == ratings[index])
			{
				sum += base + 1;
				base = 0;
				return index+1;
			}

			while(ratings[index + 1] > ratings[index])
			{
				inc++;
				index++;
				//最后的时候max是极大值
				max = ++base;
				sum += max;

				//到达末尾了
				if (index == ratings.size() - 1)
				{
					sum += base + 1;
					break;
				}
			};

			if (index == ratings.size() -1)
			{
				return -1;
			}

			//获得极大值
			max = base + 1;

			bool is_max_equal = false;

			if (ratings[index] == ratings[index + 1])
			{
				is_max_equal = true;    
			}

			//保证最少有一个dec
			do
			{
				dec++;
				index++;
			}while(index < ratings.size() - 1 && ratings[index + 1] < ratings[index]);

			if (dec >= max)
			{
				sum += get_sum(1, dec + 1);
			}
			else
			{
				sum += max;
				sum += get_sum(1, dec);
			}

			//[7,8,8,7]的情况。max = 2,dec = 2,但是8 == 8，所以两个8的值可以相等，
			if (dec == max && is_max_equal)
			{
				sum--;
			}

			base = 1;

			if (index == ratings.size() -1)
			{
				return -1;
			}
			else
			{
				return index + 1;
			}

		}
		int candy(vector<int>& ratings) {
			int index = 0, base = 0, sum = 0;
			while((index = partial_process(ratings, index, base, sum)) >= 0)
			{
			}
			return sum;
		}
};
