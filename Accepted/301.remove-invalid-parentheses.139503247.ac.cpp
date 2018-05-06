class Solution {
    set<string> res;
    string s;
    bool check() {
        int leftPs = 0;
        for (auto c : s) {
            if (c == '(') {
                leftPs++;
            } else if (c == ')') {
                leftPs--;
                if (leftPs < 0) return false;
            }
        }
        return leftPs == 0;
    }
    void bfs(int idx, int dl, int dr) {
        if (idx >= s.length()) {
            if (check()) {
                string tmp;
                for (char c : s) {
                    if (c) {
                        tmp += c;
                    }
                }
                res.insert(tmp);
            }
            return;
        }
        auto& c = s[idx];
        if (c == '(') {
            if (dl > 0) {
                c = 0;
                bfs(idx + 1, dl - 1, dr);
                c = '(';
            }           
        } else if (c == ')') {
            if (dr > 0) {
                c = 0;
                bfs(idx + 1, dl, dr - 1);
                c = ')';
            }
        }
        bfs(idx + 1, dl, dr);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        int leftPs = 0, total = 0;
        bool flag = true;
        for (auto c : s) {
            if (c == '(') {
                leftPs++;
                total++;
            } else if (c == ')') {
                leftPs--;
                if (leftPs < 0) flag = false;
                total++;
            }
        }
        int dl = 0, dr = 0;
        if (leftPs == 0 && flag) {
            return {s};
        } else if (leftPs > 0) {
            dl = leftPs;
        } else {
            dr = -leftPs;
        }
        while (dl + dr <= total) {
            bfs(0, dl, dr);
            if (!res.empty()) {
                return vector<string>(res.begin(), res.end());
            }
            dl++;
            dr++;
        }
        return {};
    }
};
