class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string resStr;
        int lspan = (numRows - 2) * 2 + 1, rspan = 0;
        if (numRows == 2) {
            lspan = 1;
        }
        int maxRow = min((int)s.length(), numRows);
        for (int curRow = 0; curRow < maxRow; curRow++) {
            int idx = curRow;
            while (true) {
                resStr.push_back(s[idx]);
                idx += (lspan == 0 ? rspan : lspan) + 1;
                if (idx >= s.length()) {
                    break;
                }
                resStr.push_back(s[idx]);
                idx += (rspan == 0 ? lspan : rspan) + 1;
                if (idx >= s.length()) {
                    break;
                }
            }
            lspan = (lspan == 1 ? 0 : lspan - 2);
            rspan = (rspan == 0 ? 1 : rspan + 2);
        }
        return resStr;
    }
};