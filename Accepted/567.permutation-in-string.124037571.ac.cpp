class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int* hash = new int[300]();
        int cur = 0;
        for (auto c: s1) {
            if (hash[c] == 0) hash[c] = 2;
            else hash[c]++;
        }
        for (int start = 0; start < s2.length(); start++) {
            char c = s2[start];
            if (hash[c] == 0) {
                for (int i = start - cur; i < start; i++) {
                    hash[s2[i]]++;
                }
                cur = 0;
            } else {
                if (hash[c] == 1) {
                    for (int i = start - cur; i < start; i++) {
                        hash[s2[i]]++;
                        cur--;
                        if (c == s2[i]) break;
                    }
                }       
                hash[c]--;
                cur++;
                if (cur == s1.length()) {
                    return true;
                }
            }
        }
        return false;
    }
};