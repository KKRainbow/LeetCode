/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching
 *
 * Hard (19.83%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * 
 */
#include<string>
using namespace std;
class Solution {
	string t;
	int tend;
	inline bool mymatch(int tidx, const string& p)
	{
		for(auto& c : p)
		{
			if(tidx >= tend)return false;
			if(c == '?')
				tidx++;
			else if(t[tidx] == c)
			{
				tidx++;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	inline string::size_type myfind(int index, const string& p, bool hasq)
	{
		if(!hasq)
		{
			return t.find(p,index);
		}
		else
		{
			for(int i = index;i<=tend - (int)p.size();i++)
			{
				if(mymatch(i, p))return i;
			}
			return string::npos;
		}
	}
	public:
	bool isMatch(string t, string p) {
		//先对p进行处理，删去多余的*和?
		this->t = t;
		this->tend = t.size();
		auto it = p.begin();
		string newp;
		string tmp;
		int ni = 0;
		int currpos = 0;
		bool startstar = false;
		bool firstword = true;
		bool hasquestion = false;
		if(p.size() == 0 && t.size() != 0)return false;
		if(p.size() != 0 && p[0] != '*')startstar = true;
		while(it != p.end())
		{
			if(*it == '?')
			{
				hasquestion = true;
				if(firstword)currpos++;
				if(currpos > t.size())return false;
				tmp.push_back(*it);
				it++;
				continue;
			}
			else if(*it != '*')
			{
				if(firstword && t[currpos++] != *it)return false;
				tmp.push_back(*it);
				it++;
				continue;
			}
			//看包不包含该字符串
			if(!firstword && tmp.size() != 0)
			{
				//currpos = t.find(tmp,currpos);
				currpos = myfind(currpos, tmp, hasquestion);
				if(currpos == string::npos)
				{
					return false;
				}
				else
				{
					currpos += tmp.size();
				}
			}
			firstword = false;
			hasquestion = false;
			tmp.clear();
			while(it != p.end())
			{
				if(*it == '*')
				{
					it++;
				}
				else
				{
					break;
				}
			}
		}
		if(firstword && currpos == t.size())return true;
		if(firstword && currpos < t.size())return false;
		if(tmp.size() != 0)//说明最后不是*
		{
			if (currpos >= t.size())return false;
			if(t.size() - tmp.size() < currpos)return false;
			if(myfind(tend - tmp.size(), tmp, hasquestion) == string::npos)
			{
				return false;
			}
		}
		return true;
	}
};

