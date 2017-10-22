class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            // even
            for (int j = i, k = i - 1; j < s.length() && k >= 0; j++,k--) {
                if (s[j] == s[k]) res++;
                else break;
            }
            // odd
            for (int j = i, k = i; j < s.length() && k >= 0; j++, k--) {
                if (s[j] == s[k]) res++;
                else break;
            }
        }
        return res;
    }
};