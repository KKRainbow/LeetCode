#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include <cmath>
using namespace std;
class Solution {
    const int MY_MIN = INT_MAX;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> index_vec(nums.size(), 0);
        vector<int> array_front_heap(nums.size());
        for (auto i = 0; i < nums.size(); i++)
        {
            nums[i].push_back(MY_MIN);
            array_front_heap[i] = i;
        }
        auto comp_func = [&index_vec, &nums](int& a_idx, int& b_idx)
        {
            return nums[a_idx][index_vec[a_idx]] > nums[b_idx][index_vec[b_idx]];
        };
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
            cout << cur_min << '\t' << cur_max << '\t' << tmp << '\t' << endl;
            if (tmp == cur_min)
            {
                cur_min = INT_MAX;
                for (int i = 0; i < nums.size(); i++)
                {
                    cur_min = min(cur_min, nums[i][index_vec[i] == nums[i].size() - 1 ? index_vec[i] - 1 : index_vec[i]]);
                }
            }
            cur_max = nums[curmin_idx][index_vec[curmin_idx]];
            
            if (cur_max - cur_min < range_right - range_left)
            {
                range_left = cur_min;
                range_right = cur_max;
            }
            
            
        }
        return {range_left, range_right};
    }
};
