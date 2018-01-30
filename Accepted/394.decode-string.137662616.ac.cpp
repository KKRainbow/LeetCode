class Solution {
    bool isNumber(const string& s) {
        return !s.empty() && all_of(s.begin(), s.end(), [](const auto& c) {return isdigit(c);});
    }
    int stringToNum(const string& s) {
        int cur = 0; 
        for (auto c : s) {
            cur *= 10;
            cur += c - '0';
        }
        return cur;
    }
public:
    string decodeString(string s) {
        stack<int> kStack;
        stack<string> strStack;  
        strStack.push("");
        int curPos = 0;
        auto getToken = [&]() {
            if (isdigit(s[curPos])) {
                int cur = curPos;
                while (isdigit(s[curPos])) curPos++;
                return string(s, cur, curPos - cur);
            } else if (isalpha(s[curPos])) {
                int cur = curPos;
                while (isalpha(s[curPos])) curPos++;
                return string(s, cur, curPos - cur);
            } else {
                auto ret = string(s, curPos, 1);
                curPos++;
                return ret;
            }
        };
        while (curPos < s.length()) {
            auto token = getToken();
            if (isdigit(token[0])) {
                kStack.push(stringToNum(token));
            } else if (isalpha(token[0])) {
                strStack.top() += token;
            } else if (token == "[") {
                strStack.push("");
            } else if (token == "]") {
                auto cs = strStack.top();
                strStack.pop();
                for (int i = 0; i < kStack.top(); i++) {
                    strStack.top() += cs;
                }
                kStack.pop();
            }
        }
        return strStack.top();
    }
};