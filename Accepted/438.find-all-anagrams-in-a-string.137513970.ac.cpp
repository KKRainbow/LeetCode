class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() == 0) return {};
        vector<int> hash(26, 0);
        for (auto c : p) {
            hash[c - 'a']++;
        }
        vector<int> res;
        int start = 0, end = p.length();
        for (int i = start; i < end; i++) {
            hash[s[i] - 'a']--;
        }
        auto check = [&hash]() -> bool {
            for (auto i : hash) {
                if (i != 0) return false;
            }
            return true;
        };
        while(1) {
            if (check()) {
                res.push_back(start);
            }
            hash[s[start] - 'a']++;
            start++;
            ++end;
            if (end > s.length()) break;
            hash[s[end - 1] - 'a']--;
        }
        return res;
    }
};