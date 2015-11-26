#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = nums1.size() + nums2.size();
        int total = count;
        count /= 2;
        count++;
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        register auto* pit = &it1;
        if(*pit == nums1.end())pit = &it2;
        if(*pit == nums2.end())return 0;
        int prev,next;
        next = **pit;
        while(count--)
        {
            prev = next;
            if(it1 == nums1.end())
                pit = &it2;
            else if(it2 == nums2.end())
                pit = &it1;
            else if(*it1 <= * it2)
                pit = &it1;
            else
                pit = &it2;
            next = **pit;
            ++*pit;
        }
        cout<<endl<<next<<'\t'<<prev<<' '<<(total&1)<<endl;
        if((total & 1) == 0)return (next*1.0 + prev)/2;
        else return next;
    }
};
