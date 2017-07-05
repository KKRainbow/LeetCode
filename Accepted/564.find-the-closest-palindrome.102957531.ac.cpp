/*
 * [564] Find the Closest Palindrome
 *
 * https://leetcode.com/problems/find-the-closest-palindrome
 *
 * Hard (16.45%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"1"'
 *
 * Given an integer n, find the closest integer (not including itself), which
 * is a palindrome. 
 * 
 * The 'closest' is defined as absolute difference minimized between two
 * integers.
 * 
 * Example 1:
 * 
 * Input: "123"
 * Output: "121"
 * 
 * 
 * 
 * Note:
 * 
 * The input n is a positive integer represented by string, whose length will
 * not exceed 18.
 * If there is a tie, return the smaller one as answer.
 * 
 * 
 */
class Solution {
	private:
		string cur_palindrome_num, cur_min_palindrome;
		uint64_t min_diff = UINT64_MAX, origin_num, cur_min_num;

		uint64_t diff(uint64_t a, uint64_t b)
		{
			return a > b ? a - b : b - a;
		}

		bool is_all(const string& str, int idx, char c)
		{
			//判断str从idx位开始，到中心对称的另一位之间的数，是否都为c
			for (int i = idx; i < str.length() - idx; i++)
			{
				if (str[i] != c)
					return false;
			}
			return true;
		}

		void make_all(string& str, int idx, char c)
		{
			for (int i = idx; i < str.length() - idx; i++)
			{
				str[i] = c;
			} 
		}

		char double_digit(string n, int idx)
		{
			int x = (n[idx] - '0') * 10 + (n[idx + 1] - '0');
			for (int to = 0; to <= 99; to += 11)
			{
				if (abs(x - to) <= 5)
					return (char)(to / 10) + '0';
			}
		}

		void try_update(const string& str)
		{
			uint64_t cur_num = strtoul(str.c_str(), nullptr, 10);
			uint64_t cur_diff = diff(cur_num, origin_num);
			if (cur_diff && (cur_diff < min_diff || (cur_diff == min_diff && cur_min_num > cur_num)))
			{
				min_diff = cur_diff;
				cur_min_palindrome = str;
				cur_min_num = cur_num;
			}
		}

		bool is_palindrome(const string& n)
		{
			for (int i = 0; i < (n.length() + 1) / 2; i++)
			{
				if (n[i] != n[n.length() - i - 1])
					return false;
			}
			return true;
		}

	public:
		string nearestPalindromic(string n) {
			origin_num = strtoul(n.c_str(), nullptr, 10);
			cur_palindrome_num = n;

			//如果小于一位，直接返回就行
			if (n.length() <= 1)
				return string(1, --n[0]);

			if (is_all(n, 0, '9'))
				return "1" + string(n.length() - 1, '0') + "1";   

			//判断是否是x0000000000000x,有可能导致总位数减少
			if ((n[0] == n[n.length() - 1]) && is_all(n, 1, '0'))
			{
				//由于不可以是自身，第一位和最后一位相等且中间为0的都会导致位数减少
				if (n[0] == '1') return string(n.length() - 1, '9');
				else return char(n[0] - 1) + string(n.length() - 2, '9') + char(n[0] - 1);
			}

			if (n[0] == '1' && is_all(n, 1, '0') && n[n.length() - 1] == '0')
				return string(n.length() - 1, '9');



			//其他情况中，不可能导致总位数的变化，我们就从第一位到中间位循环并分情况讨论即可
			int i = 0;
			if (is_palindrome(n))
			{
				i = (n.length() + 1) / 2 - 1;
			}
			for (; i < (n.length() + 1) / 2; i++)
			{
				bool is_palindrome = false;

				//当前位会加1的情况
				if (n[i] <= '8')
				{
					string tmp = cur_palindrome_num;
					if (is_all(tmp, i + 1, '9'))
					{
						make_all(tmp, i + 1, '0');
						tmp[n.length() - i - 1] = ++tmp[i];
						try_update(tmp);
					}  
				}

				//后讨论当前位会减1的情况，若当前位大于等于1，且中间位都位0，那么可能需要把该位减1
				//当diff相等时，可以把加1得到的回文顶掉，这样得到的就是更小的回文了
				if (n[i] >= '1')
				{
					string tmp = cur_palindrome_num;
					if (is_all(tmp, i + 1, '0'))
					{
						make_all(tmp, i + 1, '9');
						tmp[n.length() - i - 1] = --tmp[i];
						try_update(tmp);
					}
				}

				//当前位不变的情况。以上两种情况得到的数都已经是回文了，因此需要将差值比较小的一个留下来以备后用。
				cur_palindrome_num[n.length() - i - 1] = cur_palindrome_num[i]; 
			}
			try_update(cur_palindrome_num);

			return cur_min_palindrome.empty() ? cur_palindrome_num : cur_min_palindrome;
		}
};

