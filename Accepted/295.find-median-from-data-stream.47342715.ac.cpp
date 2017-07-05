/*
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream
 *
 * Hard (25.96%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5 
 * 
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * For example:
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * Credits:Special thanks to @Louis1992 for adding this problem and creating
 * all test cases.
 */
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

