//Partition，n(1 + 1/2 + 1/4 + ....) 复杂度 O(n)
//难点在于，如何去重
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
    //把所有不重复的正数移到数组的左端
    int dedupAndPart(vector<int>& nums)
    {
        int i = 0,j = 0;
        int num = nums.size();
        int end = nums.size();
        unordered_map<int,int> hash;
        while(j < end)
        {
            if (nums[j] <= num && nums[j] > 0 && hash[nums[j]] == 0)
            {
                hash[nums[j]] = 1;
                if (i != j)
                {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
                i++,j++;
            }
            else
            {
                j++;
            }
        }
        return i;
    }
    int partition(vector<int>& nums,int start,int end, int num)
    {
        //检查重复
        int i = start,j = start;
        while(j < end)
        {

            if (nums[j] <= num && nums[j] > 0)
            {
                if ( i != j)
                {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
                i++,j++;
            }
            else
            {
                j++;
            }
        }
        return i;
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        int start = 0,end = nums.size(),base = 0,middle = 0;
        end = dedupAndPart(nums);
        int target = end / 2;
        if (target <= 0) target  = 1;
        while(1)
        {
            middle = partition(nums, start, end, target);
            int before = middle - start;
            int after = end - middle;

            if (before == 0)//找到答案了
                return base + 1; //这里是base而不是target，如2,3,4,7,4 7中间隔了不止一个
            //不可能有其他情况
            if(before == target - base) //target选小了，小于target的数不缺。
            {
                base = target;
                start = middle;
            }
            else// if(before < target - base)
            {
                end = middle;
            }
            target = start + ((end - start)/2);
            if(target == start)target++;
        }
    }
};

int main()
{
    vector<int> nums = 
    {1,2};
    Solution s;
    cout<<s.firstMissingPositive(nums)<<endl;
    
    sort(nums.begin(),nums.end());
    for(auto i : nums)
        cout<< i<<' ';
}
