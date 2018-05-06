class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n;
        m--;
        n--;
        while (m >= 0 || n >= 0) {
            auto n1 = m >= 0 ? nums1[m] : INT_MIN;
            auto n2 = n >= 0 ? nums2[n] : INT_MIN;
            if (n1 > n2) {
                nums1[--tail] = n1;
                m--;
            } else {
                nums1[--tail] = n2;
                n--;
            }
        }
    }
};
