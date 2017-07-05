/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line
 *
 * Hard (15.34%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
	//先用O(n^2)的算法试一试，估计是不会通过的
	//先由斜率找到截距的hash表
	vector<int> multi;
	vector<Point> nodup;
	unordered_map<float,unordered_map<float,set<int>>> hashmap;
	unordered_map<float,unordered_map<float,int>> weight;
	int max = 0;
	void calc(int x,int y)
	{
		auto& a = nodup[x];
		auto& b = nodup[y];
		double slope = (a.y * 1.0 - b.y)/(a.x - b.x);
		double intercept;;   
		if (a.x == b.x)
		{
			intercept = a.x;
		}
		else
		{
			intercept = b.y - slope * b.x;
		}
		auto &n = hashmap[(float)slope][(float)intercept];
		auto &w = weight[(float)slope][(float)intercept];

		if(n.insert(x).second)
		{
			w += multi[x];
		}
		if(n.insert(y).second)
		{
			w += multi[y];	
		}

		if(w>this->max)this->max = w;
	}
	public:
	int maxPoints(vector<Point>& points) {
		this->multi.reserve(points.size());
		this->nodup.reserve(points.size());
		//去重
		for(int i = 0;i < points.size(); i++)
		{

			int multi = 1;
			for(int j = i + 1;j<points.size();j++)
			{
				//看后面有没有跟当前这个重合的点算为重数
				auto& a = points[i];
				auto& b = points[j];
				if (a.x == b.x && a.y == b.y)
				{
					multi++;
					points.erase(points.begin() + j);
					j--;
				}
			}
			this->nodup.push_back(points[i]);
			this->multi.push_back(multi);
		}

		if(nodup.size() == 1)return multi[0];

		for(int i = 0;i < points.size(); i++)
		{
			for(int j = i+1;j<points.size();j++)
			{
				calc(i,j);
			}
		}
		return this->max;
	}
};


