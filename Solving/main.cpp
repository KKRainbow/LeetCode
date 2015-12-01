#include<set>
#include<map>
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
                else return false;
            });

            typedef multiset<Building,MapComp> HMap;
            HMap heightMap;
            map<int,pair<HMap::iterator,HMap::iterator>> iterMap;
            for(auto& b : bvec)
            {
                if(!b.isEnd)
                {
                    iterMap[1] = decltype(iterMap)::value_type();
                }
            }
        }
};
