class Solution {
public:
    int maximumSwap(int num) {
        int tmp = num;
        int ldiv = -1, rdiv = -1, lbit, rbit;
        int div = 1;
        int minbit = -1, mindiv;
        while (num) {
            int bit = num % 10;
            if (minbit == -1) {
                minbit = bit;
                mindiv = div;
            } else {
                if (minbit > bit) {
                    ldiv = div;
                    rdiv = mindiv;
                    lbit = bit;
                    rbit = minbit;
                } else if (minbit < bit) {
                    mindiv = div;
                    minbit = bit;
                }
            }
            div *= 10;
            num /= 10;
        }
        if (ldiv == -1) return tmp;
        else return tmp + lbit * rdiv + rbit * ldiv - lbit * ldiv - rbit * rdiv;
    }
};
