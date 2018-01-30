class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0, ti = 0;
        while (ti < t.length() && si < s.length()) {
            if (s[si] == t[ti]) {
                si++;
                ti++;
            } else {
                ti++;
            }
        }
        return si == s.length();
    }
};