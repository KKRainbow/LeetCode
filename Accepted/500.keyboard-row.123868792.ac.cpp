class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> chs(1024);
        for (auto c: "qwertyuiopQWERTYUIOP") {
            chs[c] = 1;
        }
        for (auto c: "asdfghjklASDFGHJKL") {
            chs[c] = 2;
        }
        for (auto c: "zxcvbnmZXCVBNM") {
            chs[c] = 3;
        }
        vector<string> res;
        for (auto& str: words) {
            bool flag = true;
            for (int i = 1; i < str.length(); i++) {
                if (chs[str[i]] != chs[str[i - 1]]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(str);
        }
        return res;
    }
};