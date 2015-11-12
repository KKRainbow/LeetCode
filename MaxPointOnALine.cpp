/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#include<vector>
#include<unordered_map>
using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution {
//先用O(n^2)的算法试一试，估计是不会通过的
//先由斜率找到截距的hash表
    unordered_map<float,unordered_map<float,int>> hashmap;
    int max = 0;
    void calc(const Point& a, const Point& b, int multi)
    {
        double slope = (a.y * 1.0 - b.y)/(a.x - b.x);
        double intercept = b.y + slope * b.x;   
        auto &n = hashmap[(float)slope][(float)intercept];
        n += (n==0?2:1) + (multi - 1);
        if(n>this->max)this->max = n;
    }
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() == 1)return 1;
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
            for(int j = i+1;j<points.size();j++)
            {
                auto& a = points[i];
                auto& b = points[j];
                calc(a,b,multi);
            }
        }
        return this->max;
    }
};

int main()
{
    return 1;
}
