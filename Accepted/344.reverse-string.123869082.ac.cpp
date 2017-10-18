class Solution {
public:
    string reverseString(string s) {
        string res;
        copy(s.rbegin(), s.rend(), inserter(res, res.end()));
        return res;
    }
};