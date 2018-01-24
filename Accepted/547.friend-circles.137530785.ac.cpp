
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> s(M.size());
        for (int i = 0; i < s.size(); i++) {
            s[i] = i;
        }
        function<int(int)> findSet;
        findSet = [&](int i) -> int {
            if (s[i] == i) {
                return i;
            } else {
                s[i] = findSet(s[i]);
                return s[i];
            }
        };
        auto combine = [&](int i, int j) {
            s[findSet(i)] = findSet(j);
        };
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (M[i][j]) {
                    combine(i, j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == i) {
                res++;
            }
        }
        return res;
    }
};