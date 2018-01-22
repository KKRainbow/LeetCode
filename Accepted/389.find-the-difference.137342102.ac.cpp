class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[256];
        memset(hash, 0, 256 * sizeof(int));
        for (int i = 0; i < s.length(); i++) {
            hash[t[i]]++;
            hash[s[i]]--;
        }
        hash[t.back()]++;
        for (int a = 'a'; a <= 'z'; a++) {
            if (hash[a]) return a;
        }
        return ' ';
    }
};