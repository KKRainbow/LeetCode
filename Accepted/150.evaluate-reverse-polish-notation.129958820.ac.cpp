class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ns;
        for (auto& t: tokens) {
            if (t.length() > 1 || (t[0] >= '0' && t[0] <= '9')) {
                ns.push(atoi(t.c_str()));
            } else {
                int b = ns.top(); ns.pop();
                int a = ns.top(); ns.pop();
                int c = 0;
                switch(t[0]) {
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = a - b;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = a / b;
                        break;
                }
                //cout << a << ' ' << b << ' ' << t[0] << endl;
                ns.push(c);
            }
        }
        return ns.top();
    }
};