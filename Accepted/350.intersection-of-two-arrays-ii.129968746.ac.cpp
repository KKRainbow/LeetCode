class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (auto n : nums1) {
            m[n]++;
        }
        vector<int> res;
        for (auto n : nums2) {
            if (m[n]) {
                res.push_back(n);
                m[n]--;
            }
        }
        return res;
    }
};