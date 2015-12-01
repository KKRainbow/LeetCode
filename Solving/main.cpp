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
    int zindex = 0;
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
            int i = INT_MAX;
            int id = 0;
            vector<Building> bvec;
            for(auto& v : buildings)
            {
                Building left,right;
                left.x = v[0];
                left.isEnd = false;
                left.id = id;
                left.height = v[2];
                left.zindex = i;
                right = left;
                right.x = v[1];
                right.isEnd = true;
                bvec.push_back(left);
                bvec.push_back(right);
                id++;
                i--;
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
				        return true;
				    }
				    else
				    {
				        return false;
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
				if(currX == b.x)
				{
					auto& tmp = result[result.size() - 1];
					if(tmp.second > currHeight)tmp.second = currHeight;
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
int main()
{
	vector<vector<int>> input = 
//		{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8},};
		{{0,2,3},{2,5,3}};
	Solution s;
	auto a=  s.getSkyline(input);
	for(auto& v : a)
	{
		cout<<v.first<<' '<<v.second<<endl;
	}
	return 0;
}
