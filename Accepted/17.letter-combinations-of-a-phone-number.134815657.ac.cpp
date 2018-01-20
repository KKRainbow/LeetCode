class Solution {
    vector<string> result;
    string cur, digits;
    vector<string> keyboard = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(int pos) {
        if (pos == digits.length()) {
            result.push_back(cur);
            return;
        }
        int c = digits[pos] - '2';
        for (auto c : keyboard[c]) {
            cur[pos] = c;
            helper(pos + 1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        result.clear();
        cur = digits;
        for (auto c: digits) {
            auto tmp = c - '0';
            if (tmp <= 1 || tmp > 9) {
                return {};
            }
        }
        this->digits = digits;
        helper(0);
        return result;
    }
};