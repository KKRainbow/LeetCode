class Solution {
public:
    bool isPalindrome(int x) {
        auto r = to_string(x);
        auto i = r.begin();
        auto j = r.rbegin();
        for (; i != r.end(); i++, j++) {
            if (*i != *j) return false;
        }
        return true;
    }
};
