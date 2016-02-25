#include<set>
#include<map>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;
class MedianFinder {
	//平衡
	void balance()
	{
		auto leftSize = left.size();
		auto rightSize = right.size();
		//左多
		if(leftSize - rightSize == 1) //肯定只大了1
		{
			auto& leftMax = *left.begin();
			left.erase(left.begin());
			right.insert(leftMax);
		}
		else if(rightSize - leftSize == 2)
		{
			auto& rightMin = *right.begin();
			right.erase(right.begin());
			left.insert(rightMin);
		}
		else if(rightSize - leftSize == 1 || rightSize == leftSize)  
		{
		}
		else
		{
			//出错
			throw exception();
		}
	}
public:
	//左右两个红黑书（map）实现的优先队列，维持两个优先队列的平衡，保证右树的个数大于等于左树一个或者0个
    // Adds a number into the data structure.
	multiset<int,std::greater<int>> left; //begin最大
	multiset<int,std::less<int>> right; //begin最小
	int size = 0;
    void addNum(int num) {
		auto leftMax = *left.begin();
		auto rightMin = *right.begin();
		if(num <= leftMax)
		{
			left.insert(num);
		}
		else
		{
			right.insert(num);
		}
		size++;
		balance();
    }
    // Returns the median of current data stream
    double findMedian() {
		if((size & 1) == 1)
		{
			return *right.begin();
		}
		else
		{
			return (*left.begin()*1.0 + *right.begin())/2;
		}
    }
};
