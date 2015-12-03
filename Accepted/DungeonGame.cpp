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
