/*
 * [218] The Skyline Problem
 *
 * https://leetcode.com/problems/the-skyline-problem
 *
 * Hard (26.82%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * A city's skyline is the outer contour of the silhouette formed by all the
 * buildings in that city when viewed from a distance. Now suppose you are
 * given the locations and height of all the buildings as shown on a cityscape
 * photo (Figure A), write a program to output the skyline formed by these
 * buildings collectively (Figure B).
 * 
 * 
 * 
 * ⁠   
 * 
 * 
 * 
 * 
 * ⁠   
 * 
 * 
 * 
 * 
 * 
 * The geometric information of each building is represented by a triplet of
 * integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and
 * right edge of the ith building, respectively, and Hi is its height. It is
 * guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You
 * may assume all buildings are perfect rectangles grounded on an absolutely
 * flat surface at height 0.
 * 
 * For instance, the dimensions of all buildings in Figure A are recorded as: [
 * [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
 * 
 * The output is a list of "key points" (red dots in Figure B) in the format of
 * [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key
 * point is the left endpoint of a horizontal line segment. Note that the last
 * key point, where the rightmost building ends, is merely used to mark the
 * termination of the skyline, and always has zero height. Also, the ground in
 * between any two adjacent buildings should be considered part of the skyline
 * contour.
 * 
 * For instance, the skyline in Figure B should be represented as:[ [2 10], [3
 * 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
 * 
 * Notes:
 * 
 * ⁠The number of buildings in any input list is guaranteed to be in the range
 * [0, 10000].
 * ⁠The input list is already sorted in ascending order by the left x position
 * Li. 
 * ⁠The output list must be sorted by the x position. 
 * ⁠There must be no consecutive horizontal lines of equal height in the output
 * skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not
 * acceptable; the three lines of height 5 should be merged into one in the
 * final output as such: [...[2 3], [4 5], [12 7], ...]
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem, creating these
 * two awesome images and all test cases.
 */
#include<set>
#include<map>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;
struct Building
{
	int x;
	bool isEnd = false;
	int id;
	int height;
};
class MapComp
{
	public:
		bool operator()(const Building& a,const Building& b)
		{
			return a.height > b.height;
		}

};
class Solution {
	public:
		vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
			//在每个后面加入远近坐标
			//想了一下似乎跟zindex没什么关系。先做吧 
			int id = 0;
			vector<Building> bvec;
			for(auto& v : buildings)
			{
				Building left,right;
				left.x = v[0];
				left.isEnd = false;
				left.id = id;
				left.height = v[2];
				right = left;
				right.x = v[1];
				right.isEnd = true;
				bvec.push_back(left);
				bvec.push_back(right);
				id++;
			}
			//按X轴坐标排
			sort(bvec.begin(),bvec.end(),
					[](const Building& a,const Building& b)
					{
					if(a.x < b.x)return true;
					else if(a.x == b.x)
					{
					if(a.isEnd && b.isEnd)
					{
					if(a.height > b.height)return true;
					else return false;
					}
					else if(!a.isEnd && !b.isEnd)
					{
					if(a.height < b.height)return true;
					else return false;
					}
					else if(a.isEnd && !b.isEnd)
					{
					//一个开始，一个结束，开始的放前面
					return false;
					}
					else
					{
						return true;
					}
					return false;
					}
					else return false;
					});

			typedef multiset<Building,MapComp> HMap;
			HMap heightMap;
			map<int,HMap::iterator> iterMap;
			int currHeight = -1;
			int currX = -1;
			vector<pair<int,int>> result;
			for(auto& b : bvec)
			{
				//开头
				if(!b.isEnd)
				{
					auto& pos = iterMap[b.id];
					pos = heightMap.insert(b);
				}
				else
				{
					auto iter= iterMap.find(b.id);
					heightMap.erase(iter->second);
					iterMap.erase(iter);
				}

				auto nearestIter = heightMap.begin();
				if(nearestIter == heightMap.end())
				{
					currHeight = 0;
				}
				else if(currHeight != nearestIter->height)
				{
					currHeight = nearestIter->height;

				}
				else
					continue;

				if(currX == b.x)
				{
					auto& tmp = result[result.size() - 1];
					if(b.isEnd && tmp.second > currHeight)tmp.second = currHeight;
					else if(!b.isEnd && tmp.second < currHeight)tmp.second = currHeight;
				}
				else
				{
					result.push_back(make_pair(b.x,currHeight));
				}
				currX = b.x;
			}
			return result;
		}
};

