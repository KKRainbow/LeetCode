class Solution {
    int countBit(int n) {
        int sum = 0;
        while (n) {
            if ((n & 1) == 1) {
                sum++;
            }
            n >>= 1;
        }
        return sum;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<vector<string>> minute(7), hour(5);
        for (int i = 0; i < 60; i++) {
            if (i < 12) {
                char str[4];
                sprintf(str, "%d", i);
                hour[countBit(i)].push_back(str);
            }
            char str[10];
            sprintf(str, "%02d", i);
            minute[countBit(i)].push_back(str);
        }
        vector<string> res;
        for (int i = 0; i <= 4; i++) {
            int j = num - i;
            if (j >= 0 && j <= 6) {
                for (auto& h : hour[i]) {
                    for (auto& m : minute[j]) {
                        res.push_back(h + ":" + m);
                    } 
                }
                
            }
        }
        return res;
    }
};