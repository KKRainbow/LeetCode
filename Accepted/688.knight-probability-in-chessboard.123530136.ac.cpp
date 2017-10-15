class Solution {
    int MK;
    double* cache = nullptr;
public:
    double helper(int N, int K, int r, int c) {
        double res = 0;
        if (!(r < N && r >= 0 && c < N && c >= 0)) {
            return 0;
        }
        if (K <= 0) {
            return 1;
        }
        double& ca = cache[N * MK * r + MK * c + K];
        if (!isnan(ca)) {
            return ca;
        }
        int as[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int bs[] = {1, -1, 1, -1, 2, -2, 2, -2};
        for (int i = 0; i < 8; i++) {
            int newr = r + as[i];
            int newc = c + bs[i];
            if (newr < N && newr >= 0 && newc < N && newc >= 0) {
                res += (1.0 / 8.0) * helper(N, K - 1, newr, newc);
            }
        }
        ca = res;
        return res;
    }
    double knightProbability(int N, int K, int r, int c) {
        if (cache) {
            delete cache;
        }
        cache = new double[N * N * K];
        fill(cache, cache + N * N * K, NAN);
        MK = K;
        return helper(N, K, r, c);
    }
};