class Solution {
public:
    int hIndex(vector<int>& cs) {
        sort(cs.begin(), cs.end());
        int res = 0;
        int i;
        for (i = 0; i <= cs.size(); i++) {
            if ((i == 0 || cs[cs.size() - i] >= i) && (i == cs.size() || cs[cs.size() - i - 1] <= i)) {
                res = max(res, i);
            }
        }
        return res;
    }
};