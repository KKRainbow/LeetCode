#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include <cmath>
using namespace std;

class Solution {
	public:
		int reversePairs(vector<int>& nums) {
			//思路：从后往前遍历，遍历过程中进行排序，并利用一个数组快速算出比他的二分之一还小的数的个数
			//难点：1、如何处理负数。
			int pos_stat[32], neg_stat[32]; //落在每个区间的数的个数统计

			//pos_stat[i] 代表了小于等于2^i的个数     (-1, 1] (-1, 2] (-1, 4] (-1, 8] (-1, 16].....
			//neg_stat[i] 代表了大于等于-2^i的个数    [-1, 0) [-2, 0) [-4, 0) [-8, 0) [-16, 0).....

			int size = nums.size();
			int pos_neg_bound = size; //正负数的分界点

			memset(pos_stat, 0, sizeof(pos_stat));
			memset(neg_stat, 0, sizeof(neg_stat));

			int total_count = 0;

			//nums = [5,2,7,9,4,-1,||4 -12, -10, -3,| 0, 0, 1, 3,7]; ->数组大概长这样 || 代表了处理到的位置， |代表了正负数分界点
			for (int i = size - 1; i >= 0; i--)
			{
				int cur = nums[i];
				int count = 0;
				if (cur > 0)
				{
					int cur_div2 = (cur - 1) / 2;
					int cur_log2 = cur_div2 != 0 ? (int)log2(abs(cur_div2)) : 0;
					//如果是正数，就找比该数二分之一还小的正数，并且加上所有的负数
					count = pos_neg_bound - i - 1; //负数的个数
					int cur_positive_pos = pos_neg_bound;

					//对cur=1和2要做特殊处理，因为cur_div2是0，不能正确的计算log2,此时不能用pos_stat提供的数据，while循环会
					//计算0的个数
					if (cur > 2)
					{
						count += pos_stat[cur_log2];
						cur_positive_pos += pos_stat[cur_log2];
						//看能不能找到更多满足要求的
					}
					while (cur_positive_pos < size && nums[cur_positive_pos++] <= cur_div2)
					{
						count++;
					}
					//正数就处理到这。
				}
				else if (cur < 0 && cur != INT32_MIN)
				{
					int cur_div2 = (cur / 2) - 1;
					int cur_log2 = cur_div2 != 0 ? (int)log2(abs(cur_div2)) : 0;
					//如果是负数，就在负数中找比cur_div2更远离0的数的个数。
					count = neg_stat[31] - neg_stat[cur_log2 + 1];
					int cur_negative_pos = count + i + 1;
					while (cur_negative_pos < pos_neg_bound && nums[cur_negative_pos++] <= cur_div2)
					{
						count++;
					}
				}
				//如果是0，只需要算负数的个数即可
				else
				{
					count = pos_neg_bound - i - 1; //负数的个数
				}

				//现在开始排序，并维护stat数据结构(用小于等于是为了更方便的维护正负边界)
				//最好用binary search+memmove，内存操作比swap操作更快，不然此处会成为性能瓶颈
				int insert_pos = i + 1;
				int* data = nums.data();
				auto iter = upper_bound(data + insert_pos, data + size, cur);
				insert_pos = iter - data;
				memmove(data + i, data + i + 1, ((iter - data) - i - 1) * sizeof(int));
				*(iter - 1) = cur;

				//维护stat结构体
				if (cur >= 0)
				{
					int tmp = 0x40000000;
					pos_stat[31]++;
					for (int x = 30; cur <= tmp && x >= 0; x--)
					{
						pos_stat[x]++;
						tmp /= 2;
					}
				}
				else if (cur < 0)
				{
					int tmp = INT32_MIN;
					for (int x = 31; cur >= tmp; x--)
					{
						neg_stat[x]++;
						tmp /= 2;
					}
				}
				//维护正负边界，如果插入到了正负边界的右边，那么就需要将正负边界减1，否则不变。
				//只有插入的数大于等于0，正负边界才会变
				if (cur >= 0 && insert_pos >= pos_neg_bound)
					pos_neg_bound--;

				//把此次统计得到的数据加到total里。
				total_count += count;
			}
			return total_count;
		}
};

int main()
{
	Solution s;
	vector<int> v = 
	//{1,3,-3,3,1};
	//{-1,-2, -3, -4, -5};
	//{2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
	{-62,50,-35,58,181,-58,-161,330,198,326,263,396,252,-31};
	cout << s.reversePairs(v) << endl;
	return 0;
}
