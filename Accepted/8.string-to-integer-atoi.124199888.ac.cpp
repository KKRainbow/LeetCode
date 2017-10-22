class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        auto iter = str.begin();
        while (*iter == ' ') iter++;
        int sign = *iter == '-' ? -1 : 1;
        if (*iter == '-' || *iter == '+') iter++;
        long long res = 0;
        while (iter != str.end()) {
            if (*iter < '0' || *iter > '9' || res > INT_MAX) break;
            res = res * 10 + (*iter - '0');
            iter++;
        }
        auto r = res * sign;
        if (r > INT_MAX) return INT_MAX;
        else if (r < INT_MIN) return INT_MIN;
        else return r;
    }
};