/*
 * [440] K-th Smallest in Lexicographical Order
 *
 * https://leetcode.com/problems/k-th-smallest-in-lexicographical-order
 *
 * Hard (24.05%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '13\n2'
 *
 * Given integers n and k, find the lexicographically k-th smallest integer in
 * the range from 1 to n.
 * 
 * Note: 1 ≤ k ≤ n ≤ 109.
 * 
 * Example:
 * 
 * Input:
 * n: 13   k: 2
 * 
 * Output:
 * 10
 * 
 * Explanation:
 * The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so
 * the second smallest number is 10.
 * 
 * 
 */
class Solution {
	int string2num(const string& str)
	{
		int d;
		stringstream ss(str);
		ss >> d;
		return d;
	}
	public:
	int findKthNumber(int n, int k) {
		/*
		 * 思路：若1开头的数字的个数小于k，那么结果肯定不是以1开头，而是以>1的数开头。
		 * 若1开头的数字的个数大于k，那么就尝试10开头，11开头，12开头，直至k落入某个区间。比如在15开头的区间内
		 * 然后尝试150开头， 151开头。。。等等等等
		 */
		string str_n; //k的范围是1到10^9，转换成字符串更好处理
		stringstream ss;
		ss << n;
		str_n = ss.str();

		string prefix = "1";
		int count = 0; //词法序小于当前前缀的数的个数
		while (count != k)
		{
			//计算在词法序排序的序列中中具有当前前缀的数的个数
			int cur_count = 0;  //此为得到的结果
			int prefix_num = string2num(prefix);
			int prefix_of_n_num = string2num(str_n.substr(0, prefix.length()));
			if (prefix_num < prefix_of_n_num)
			{
				cur_count = string2num(string(str_n.length() - prefix.length() + 1, '1'));
			}
			else if (prefix_num == prefix_of_n_num)
			{
				int tmp = string2num(string(str_n.length() - prefix.length(), '1'));
				cur_count = tmp + string2num(str_n.substr(prefix.length())) + 1;
			}
			else
			{
				cur_count = string2num(string(str_n.length() - prefix.length(), '1'));
			}
			if (cur_count + count < k)
			{
				count += cur_count;
				assert(prefix[prefix.length() - 1]++ != '9');
			}
			else 
			{
				count += 1;
				if (count != k) prefix += '0';
			}
		}
		return string2num(prefix);
	}
};

