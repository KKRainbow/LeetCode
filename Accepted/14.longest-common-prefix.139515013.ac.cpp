class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string tmp = strs[0];
        int end = tmp.length();
        for (auto &str : strs) {
            int curIdx = 0;
            while (curIdx < str.length() && curIdx < end && str[curIdx] == tmp[curIdx]) {
                curIdx++;
            }
            end = curIdx;
            if (!end) {
                return "";
            }
        }
        return tmp.substr(0, end);
    }
};
