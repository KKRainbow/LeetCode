class Solution {
public:
    int calculate(string s) {
        map<char, int> priv = {
            {'+', 0},
            {'-', 0},
            {'*', 1},
            {'/', 1},
            {'^', -1},
            {'$', -2},
        };
        stack<int> oper;
        stack<char> oprn;
        oprn.push('^');
        int cur = 0;
        s += '$';
        for (auto c : s) {
            if (isspace(c)) {
                continue;
            } else if (isdigit(c)) {
                cur *= 10;
                cur += c - '0';
            } else {
                while (priv[c] <= priv[oprn.top()]) {
                    switch(oprn.top()) {
                        case '+':
                            cur += oper.top();
                            break;
                        case '-':
                            cur = oper.top() - cur;
                            break;
                        case '*':
                            cur *= oper.top();
                            break;
                        case '/':
                            cur = oper.top() / cur;
                            break;
                        case '^':
                            return cur;
                    }
                    oper.pop();
                    oprn.pop();
                }
                oper.push(cur);
                oprn.push(c);
                cur = 0;
            }
        }
        return -1;
    }
};