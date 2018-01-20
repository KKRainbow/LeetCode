class Solution {
    vector<int> nums;
    int findMed(int s, int e, int k) {
        swap(nums[s], nums[(rand() % (e - s)) + s]);
        int os = s, oe = e, pivot = nums[s];
        //cout << os << ' ' << oe << ' ' << pivot << ' ' << k << endl;
        s++;
        while (s != e) {
            if (nums[s] <= pivot) {
                s++;
            } else {
                swap(nums[s], nums[e - 1]);
                e--;
            }
        }
        swap(nums[s - 1], nums[os]);
        s--;
        if (s - os == k) {
            return nums[s];
        } else if (s - os > k) {
            return findMed(os, s, k);
        } else {
            return findMed(s + 1, oe, k - (s - os) - 1);
        }
    }
public:
    int minMoves2(vector<int>& nums) {
        if (nums.empty()) return 0;
        this->nums = nums;
        int med = findMed(0, nums.size(), nums.size() / 2);
        int res = 0;
        for (auto i : nums) {
            res += abs(i - med);
        }
        return res;
    }
};