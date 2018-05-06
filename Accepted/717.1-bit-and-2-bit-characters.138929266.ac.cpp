class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.back() == 1) {
            return false;
        }
        int count = 0, idx = bits.size() - 2;
        while (idx >= 0 && bits[idx--]) count++;
        return !(count & 1);
    }
};
