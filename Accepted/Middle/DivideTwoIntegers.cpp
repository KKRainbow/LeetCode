//
// Created by sunsijie on 16-3-1.
//

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        if (!divisor) {
            return INT_MAX;
        }
        if (divisor == INT_MIN && dividend == INT_MIN) {
            return 1;
        }
        if (divisor == INT_MIN) {
            return 0;
        }
        if (dividend == INT_MIN) {
            res++;
            if (divisor > 0) {
                dividend += abs(divisor);
            } else {
                dividend -= divisor;
            }
        }
        int origin = divisor;
        int flag = dividend < 0 ? -1 : 1;
        int flag2 = divisor < 0 ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);

        int power = 0;
        while (divisor > 0 && dividend > divisor) {
            divisor <<= 1;
            power++;
        }

        if (power > 0) {
            power--;
            divisor = (unsigned)divisor >> 1;
        }

        while (dividend >= abs(origin)) {
            if (dividend - divisor >= 0) {
                dividend -= divisor;
                res += 1<<power;
            } else {
                power--;
                divisor >>= 1;
            }
        }

        if (res < 0) {
            return INT_MAX;
        }

        if (flag != flag2) {
            return -res;
        } else {
            return res;
        }
    }
};

int main(int argc, char* argv[], char* env[])
{
    Solution s;
    int a = -1010369383;
    int b = -2147483648;
    cout<<INT_MIN<<endl;
    cout<<s.divide(b, -1)<<endl;
    cout<<b/-1<<endl;
}
