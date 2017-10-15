class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int o = n, 
                     p = (1 << ((int)log2(n) + 1)) - n - 1,
                     a = 0b10101010101010101010101010101010,
                     b = 0b01010101010101010101010101010101;
        return ((o&a)==o && (p & b) == p) || ((o&b) == o && (p & a) == p);
    }
};