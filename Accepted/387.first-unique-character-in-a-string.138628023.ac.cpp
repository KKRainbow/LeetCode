class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(256);
        for (auto c : s) {
            hash[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (hash[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
