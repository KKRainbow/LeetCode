/*
 * [632] Smallest Range
 *
 * https://leetcode.com/problems/smallest-range
 *
 * Hard (45.12%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in ascending order. Find the smallest
 * range that includes at least one number from each of the k lists. 
 * 
 * We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c
 * if b-a == d-c.
 * 
 * Example 1:
 * 
 * Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * Output: [20,24]
 * Explanation: 
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The given list may contain duplicates, so ascending order means >= here.
 * 1 <= k <= 3500
 * ⁠-105 <= value of elements <= 105.
 * For Java users, please note that the input type has been changed to
 * List<List<Integer>>. And after you reset the code template, you'll see this
 * point.
 * 
 * 
 * 
 */
class Solution {
	const int MY_MIN = INT_MAX;
	public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		vector<int> index_vec(nums.size(), 0);
		vector<int> array_front_heap(nums.size());
		vector<int> cur_frame_heap(nums.size());
		auto frame_comp = greater<int>();
		for (auto i = 0; i < nums.size(); i++)
		{
			nums[i].push_back(MY_MIN);
			array_front_heap[i] = i;
			cur_frame_heap[i] = nums[i][0];
		}
		auto comp_func = [&index_vec, &nums](int& a_idx, int& b_idx)
		{
			return nums[a_idx][index_vec[a_idx]] > nums[b_idx][index_vec[b_idx]];
		};

		make_heap(cur_frame_heap.begin(), cur_frame_heap.end(), frame_comp);

		make_heap(array_front_heap.begin(), array_front_heap.end(), comp_func);

		int range_left = 0, range_right = INT_MAX;
		int cur_min = INT_MAX, cur_max = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			cur_min = min(cur_min, nums[i][index_vec[i] == nums[i].size() - 1 ? index_vec[i] - 1 : index_vec[i]]);
			cur_max = max(cur_max, nums[i][index_vec[i] == nums[i].size() - 1 ? index_vec[i] - 1 : index_vec[i]]);
		}
		range_left = cur_min;
		range_right = cur_max;

		while (1)
		{
			pop_heap(array_front_heap.begin(), array_front_heap.end(), comp_func);
			int curmin_idx = array_front_heap[array_front_heap.size() - 1];
			int tmp = nums[curmin_idx][index_vec[curmin_idx]++];
			push_heap(array_front_heap.begin(), array_front_heap.end(), comp_func);
			if (tmp == MY_MIN)
				break;
			int cand = nums[curmin_idx][index_vec[curmin_idx]];
			//cout << cur_min << '\t' << cur_max << '\t' << cand << '\t' << tmp << endl;

			if (tmp == cur_min)
			{
				pop_heap(cur_frame_heap.begin(), cur_frame_heap.end(), frame_comp);
				if (cand != MY_MIN)
					cur_frame_heap[cur_frame_heap.size() - 1] = cand;
				push_heap(cur_frame_heap.begin(), cur_frame_heap.end(), frame_comp);
				cur_min = cur_frame_heap[0];
			}
			if (cand > cur_max && cand != MY_MIN)
			{
				cur_max = cand;
			}

			if (cur_max - cur_min < range_right - range_left)
			{
				range_left = cur_min;
				range_right = cur_max;
			}


		}
		return {range_left, range_right};
	}
};
