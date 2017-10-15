class Solution {
public:
    vector<int> grayCode(int n) {
        if (!n) return {0};
        unsigned int base = 2;
        vector<int> res{0, 1};
        while (--n) {
            size_t e = res.size();
            for (int i = e - 1; i >= 0; i--) {
                res.push_back((int)base | res[i]);
            }
            base <<= 1;
        }
        return res;
    }
};