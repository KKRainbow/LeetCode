class Solution {
public:
    vector<int> countBits(int num) {
        // just dp it
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i - (i & (-i))] + 1;
        }
        return res;
    }
};