class Solution {
    uint32_t encode(char c) {
        switch(c) {
            case 'A':
                return 0b00;
            case 'T':
                return 0b01;
            case 'C':
                return 0b11;
            case 'G':
                return 0b10;
        }
    }
    char decode(uint32_t c) {
        switch(c) {
            case 0b00:
                return 'A';
            case 0b01:
                return 'T';
            case 0b11:
                return 'C';
            case 0b10:
                return 'G';
        }
    }
    string decodeString(uint32_t seq) {
        string res;
        for (int i = 0; i < 10; i++) {
            res += decode(seq & 0b11);
            seq >>= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        vector<int> m(1<<20);
        auto mask = (1<<20) - 1;
        uint32_t start = 0;
        for (int i = 0; i < s.length(); i++) {
            start |= encode(s[i]);
            if (i >= 9) {
                if (m[start] == 1) {
                    res.push_back(decodeString(start));
                }
                m[start]++;
            }
            start <<= 2;
            start &= mask;
        }
        return res;
    }
};