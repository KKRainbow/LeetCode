class Solution {
public:
    string intToRoman(int num) {
        stringstream ss;
        auto func = [&](int minVal, const string& str) {
            while (num >= minVal) {
                ss << str;
                num -= minVal;
            }
        };
        vector<pair<int, string>> vec{
            { 1000, "M" },
            { 900, "CM" },
            { 500, "D" },
            { 400, "CD" },
            { 100, "C" },
            { 90, "XC" },
            { 50, "L" },
            { 40, "XL" },
            { 10, "X" },
            { 9, "IX" },
            { 5, "V" },
            { 4, "IV" },
            { 1, "I" },
        };
        for (auto& p : vec) {
            func(p.first, p.second);
            if (num == 0) break;
        }
        return ss.str();
    }
};
