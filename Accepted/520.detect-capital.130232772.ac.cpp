class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() <= 1) return true;
        int f = isupper(word[1]);
        for (int i = 2; i < word.length(); i++) {
            if (f != isupper(word[i])) {
                return false;
            }
        }
        return isupper(word[0]) || !f;
    }
};