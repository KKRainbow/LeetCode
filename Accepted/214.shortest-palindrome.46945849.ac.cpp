/*
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome
 *
 * Hard (23.96%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"aacecaaa"'
 *
 * 
 * Given a string S, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 * 
 * 
 * For example: 
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Thanks to @Freezen for additional test cases.
 */
#include<vector>
#include<iostream>
using namespace std;
class Solution {
	int calculatedNext = 0;
	vector<int> next;
	string str;
	int getNext(int index)
	{
		if(index >= next.size())next.resize(index + 10);
		if(index <= calculatedNext)
		{
			return next[index];
		}
		else
		{
			if(calculatedNext == 0) //还没初始化
			{
				next[calculatedNext++] = 0; //idx = 1
				next[calculatedNext++] = 0; //idx = 2
			}
			for(int i = calculatedNext; i<= index; i++)
			{
				//aac
				//aaa
				int t = i - 1;
				while(str[i - 1] != str[next[t]] && t != 0)
				{
					t = next[t];
				}
				next[i] = str[i-1] == str[next[t]] ? next[t] + 1 : 0;
			}
			if(index > calculatedNext)calculatedNext = index;
			cout<<' '<<index<<' '<<next[index]<<endl;
			return next[index];
		}
	}
	public:
	string shortestPalindrome(string s) {
		if(s.size() <= 1)return s;
		str = s;

		int front = 0;
		int back = s.size() - 1;
		while(front <= back)
		{
			if(s[front] == s[back])
			{
				front++;
				back--;
			}
			else if(front == 0)
			{
				back--;
			}
			else
			{
				front = getNext(front);
			}
		}

		string res;
		int rend = back + front;
		for(int i = s.size() - 1;i>rend;i--)
		{
			res.push_back(s[i]);
		}
		res.insert(res.end(),s.begin(),s.end());

		return res;
	}
};
