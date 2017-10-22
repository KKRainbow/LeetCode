class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        // 注意到 F(n) = F(n-1) - (size * A[n]) + (sum - A[n])
        int f = 0;
        int sum = 0; 
        int res;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            f += i * A[i];
        }
        res = f;
        int newf;
        for (int i = A.size() - 1; i > 0; i--) {
            newf = f - (A.size() - 1) * A[i] + (sum - A[i]);
            res = max(res, newf);
            f = newf;
        }
        return res;
    }
};