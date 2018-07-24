class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            int cur = 1 << i;
            auto c = a & cur;
            auto d = b & cur;
            auto pos = (c ^ d) ^ (carry << i);
            sum |= pos;
            if ((carry == 1 && (c != 0 || d != 0)) || (c != 0 && d != 0)) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        return sum;
    }
};
