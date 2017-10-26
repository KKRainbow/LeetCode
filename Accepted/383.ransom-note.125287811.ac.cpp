class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(1 << 8);
        for (auto &c : magazine) {
            m[c]++;
        }
        for (auto &c : ransomNote) {
            m[c]--;
            if (m[c] < 0) {
                return false;
            }
        }
        return true;
    }
};