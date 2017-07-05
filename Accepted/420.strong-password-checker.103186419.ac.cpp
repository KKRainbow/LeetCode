/*
 * [420] Strong Password Checker
 *
 * https://leetcode.com/problems/strong-password-checker
 *
 * Hard (19.95%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""'
 *
 * A password is considered strong if below conditions are all met:
 * 
 * 
 * ⁠It has at least 6 characters and at most 20 characters. 
 * ⁠It must contain at least one lowercase letter, at least one uppercase
 * letter, and at least one digit. 
 * ⁠It must NOT contain three repeating characters in a row ("...aaa..." is
 * weak, but "...aa...a..." is strong, assuming other conditions are met). 
 * 
 * 
 * Write a function strongPasswordChecker(s), that takes a string s as input,
 * and return the MINIMUM change required to make s a strong password. If s is
 * already strong, return 0.
 * 
 * Insertion, deletion or replace of any one character are all considered as
 * one change.
 */
class Solution {
	public:
		int strongPasswordChecker(string s) {
			return min(impl(s), impl(string(s.rbegin(), s.rend())));
		}
		int impl(string s) {
			//该问题的核心是如何解决条件3.前两个条件可以再解决条件3的基础上解决。
			int over = 0, missing = 0;
			if (s.length() < 6) missing = 6 - s.length();
			if (s.length() > 20) over = s.length() - 20;

			int replace = 0, remove = 0, insert = 0;
			int first = 0, last = 0, cont = 0;

			//处理连续字符的函数，优先通过增删解决，其次通过replace解决
			auto func = [&](int first, int last)
			{
				int count = last - first;
				if (count <= 2) return;
				if (missing > 0)
				{
					//看增加几个可以解决
					int add = (count - 1) / 2;
					if (missing >= add) //可以增加的字符数目足够，那么直接添上就好了
					{
						missing -= add;
						insert += add;
						return;
					}
					else
					{
						missing = 0;
						first += 2 * missing;
						insert += missing;
						if (last - first <= 2)
							return;
						//还需要replace来解决
					}
				}
				else if (over > 0)
				{
					//把重复的个数减少到3m + 2（2,5,8,11,13)这样需要的replace次数最少
					int del =  0;
					if (count >= over)
					{
						del = (count - 2) - ((count - 2) / 3) * 3;
						del += ((over-del) / 3) * 3;
					}
					else
					{
						del = (count - 2) - ((count - 2) / 3) * 3;
						del += ((count-del) / 3) * 3;
					}
					if (((del + (count - del) / 3) > (count / 3)) && del > over)
					{
						del = 0;
					}
					//删除之后仍然需要到替换步骤去看一下还需要替换多少
					int min_del_over = min(over, del);
					over -= min_del_over;
					remove += min_del_over;
					first += min_del_over;
				}

				//经过了增删，需要处理的重复字符个数已经发生了变化。
				count = last - first;
				replace += count / 3;
			};

			//字符串中，数字，大小写出现的个数
			int digit = 0, lower = 0, upper = 0;
			while (1)
			{
				if (first >= s.length()) break;
				if (s[last] == s[first]) 
				{
					cont++;
					last++;
				}
				else 
				{
					if (isdigit(s[first])) digit++;
					else if (islower(s[first])) lower++;
					else if (isupper(s[first])) upper++;
					//出现了连续3次，first是第一次出现， last-1是最后一次出现，cont是出现的次数。
					func(first, last);
					first = last;
					cont = 0;
				}
			}

			//如果此时insert和replace操作数之和大于2，那么肯定满足条件2
			int cond2 = (digit == 0) + (lower == 0) + (upper == 0);
			int extra = max(0, cond2 - (insert + missing + replace)); //仍需进行的额外操作数目，以满足条件2；
			return missing + over + extra + replace + remove + insert;
		}
};

