class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() <= 2) return 0;
        int cur = A[1] - A[0], curLen = 1, sum = 0;
        for (int i = 2; i <= A.size(); i++) {
            int diff = cur + 1;
            if (i < A.size()) {
                diff = A[i] - A[i - 1];
            }
            if (diff != cur) {
                sum += (curLen * (curLen - 1)) / 2;
                cur = diff;
                curLen = 1;
            } else {
                curLen++;
            }
        }
        return sum;
    }
};