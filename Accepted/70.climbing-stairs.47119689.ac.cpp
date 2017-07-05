/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs
 *
 * Easy (39.69%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * 
 * Note: Given n will be a positive integer.
 * 
 */
#include<algorithm>
using namespace std;
class Solution {
	void m(int d[],int s[],int t[])
	{
		d[0] = s[0]*t[0] + s[1] * t[2];
		d[1] = s[0] * t[1] + s[1] * t[3];

		d[2] = s[2] * t[0] + s[3] * t[2];
		d[3] = s[2] * t[1] + s[3] * t[3];
	}
	void c(int d[], int s[])
	{
		copy(s,s+4,d);
	}
	public:
	int climbStairs(int n) {
		int matrix[] = {1,1,1,0};
		int start[] = {1,0,1,0};
		int tmp[4] = {0,};
		while(n)
		{
			if(n & 1)
			{
				m(tmp,start,matrix);
				c(start,tmp);
			}
			m(tmp,matrix,matrix);
			c(matrix,tmp);
			n>>=1;
		}
		return start[0];
	}
};

