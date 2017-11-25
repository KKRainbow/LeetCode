class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int lb = max(idx - k, 0);
        int resb = lb;
        int curSum = 0;
        for (int i = lb; i < lb + k; i++) {
            curSum += abs(arr[i] - x);
        }
        lb++;
        for (; lb + k <= arr.size(); lb++) {
            int minus = abs(arr[lb - 1] - x);
            int plus = abs(arr[lb + k - 1] - x);
            if (plus > minus) break;
            int tmp = curSum - minus + plus; 
            if (tmp < curSum) {
                curSum = tmp;
                resb = lb;
            }
        }
        return vector<int>(arr.begin() + resb, arr.begin() + resb + k);
    }
};