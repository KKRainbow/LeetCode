class Solution {
public:
    int findComplement(int num) {
        return (1 << (int(log2(num)) + 1)) - num - 1;
    }
};