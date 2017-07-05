/*
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix
 *
 * Medium (44.28%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */
class Solution {
	public:
		int kthSmallest(vector<vector<int>>& matrix, int k) {
			multimap<int, pair<int, int>> prio_queue = 
			{ {matrix[0][0], {0, 0}} };
			for (int i = 1; i < k; i++)
			{
				auto iter = prio_queue.begin();
				if (iter->second.first + 1 < matrix.size())
				{
					prio_queue.insert({   
							matrix[iter->second.first + 1][iter->second.second], 
							{iter->second.first + 1, iter->second.second}
							});
					matrix[iter->second.first + 1][iter->second.second] = INT_MAX;
				}
				if (iter->second.second + 1 < matrix.size())
				{
					prio_queue.insert({   
							matrix[iter->second.first][iter->second.second + 1], 
							{iter->second.first, iter->second.second + 1}
							});
					matrix[iter->second.first][iter->second.second + 1] = INT_MAX;
				}
				prio_queue.erase(iter);
			}
			return prio_queue.begin()->first;
		}
};
