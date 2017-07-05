/*
 * [174] Dungeon Game
 *
 * https://leetcode.com/problems/dungeon-game
 *
 * Hard (23.57%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[[0]]'
 *
 * 
 * table.dungeon, .dungeon th, .dungeon td {
 * ⁠ border:3px solid black;
 * }
 * 
 * ⁠.dungeon th, .dungeon td {
 * ⁠   text-align: center;
 * ⁠   height: 70px;
 * ⁠   width: 70px;
 * }
 * 
 * 
 * The demons had captured the princess (P) and imprisoned her in the
 * bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid
 * out in a 2D grid. Our valiant knight (K) was initially positioned in the
 * top-left room and must fight his way through the dungeon to rescue the
 * princess. 
 * The knight has an initial health point represented by a positive integer. If
 * at any point his health point drops to 0 or below, he dies immediately. 
 * Some of the rooms are guarded by demons, so the knight loses health
 * (negative integers) upon entering these rooms; 
 * other rooms are either empty (0's) or contain magic orbs that increase the
 * knight's health (positive integers).
 * In order to reach the princess as quickly as possible, the knight decides to
 * move only rightward or downward in each step. 
 * 
 * 
 * Write a function to determine the knight's minimum initial health so that he
 * is able to rescue the princess.
 * For example, given the dungeon below, the initial health of the knight must
 * be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN ->
 * DOWN.
 * 
 * 
 * ⁠
 * -2 (K) 
 * -3 
 * 3 
 * ⁠
 * ⁠
 * -5 
 * -10 
 * 1 
 * ⁠
 * ⁠
 * 10 
 * 30 
 * -5 (P) 
 * ⁠
 * 
 * 
 * 
 * 
 * Notes:
 * 
 * The knight's health has no upper bound.
 * Any room can contain threats or power-ups, even the first room the knight
 * enters and the bottom-right room where the princess is imprisoned.  
 * 
 * 
 * 
* Credits:Special thanks to @stellari for adding this problem and creating all
* test cases.
*/
#include<set>
#include<map>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
	void calc(vector<vector<int>>& res,vector<vector<int>>& dungeon,int i,int j)
	{
		auto right = res[i][j+1];
		auto left = res[i+1][j];
		auto& dest = res[i][j];
		auto val = dungeon[i][j];

		auto minHeal = min(left,right);

		if(val >= 0)
		{
			auto tmp = minHeal - val;
			dest = tmp > 0 ?tmp : 1;
		}
		else
		{
			dest = minHeal - val;
		}
	}
	public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int row = dungeon.size();
		if(row == 0)return 1;
		int col = dungeon[0].size();
		auto& resMatrix = dungeon;

		auto m =  dungeon[row-1][col-1];
		resMatrix[row - 1][col - 1] = m >= 0 ? 1 : abs(m) + 1;
		//构造最后一行，最后一列。
		for(int j = col - 2; j >= 0;j--)
		{
			auto to = resMatrix[row - 1][j + 1];
			auto& from = resMatrix[row - 1][j];
			auto val = dungeon[row - 1][j];
			if(val >= 0)
			{
				auto tmp = to - val;
				from = tmp > 0 ?tmp : 1;
			}
			else
			{
				from = to - val;
			}
		}

		//最后一列
		for(int i = row - 2; i >= 0;i--)
		{
			auto to = resMatrix[i + 1][col - 1];
			auto& from = resMatrix[i][col - 1];
			auto val = dungeon[i][col - 1];
			if(val >= 0)
			{
				auto tmp = to - val;
				from = tmp > 0 ?tmp : 1;
			}
			else
			{
				from = to - val;
			}
		}

		for(int i = row - 2;i >= 0;i--)
			for(int j = col - 2;j >= 0;j--)
			{
				calc(resMatrix,dungeon,i,j);
			}


		return resMatrix[0][0];
	}
};

