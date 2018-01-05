class Solution {
    string goodStr;
    vector<string> result;
    int n;
    void search(int curPos, int unclosed) {
        if (curPos == 2 * n) {
            if (unclosed == 0) {
                result.push_back(goodStr);
            }
            return;
        }
        int remainRight = n - ((curPos - unclosed) / 2);
        int remainLeft = n - ((curPos + unclosed) / 2);
        if (remainLeft + unclosed > remainRight) {
            return;
        }
        if (remainLeft > 0) {
            goodStr[curPos] = '(';
            search(curPos + 1, unclosed + 1);
        }
        if (remainRight > 0 && unclosed > 0) {
            goodStr[curPos] = ')';
            search(curPos + 1, unclosed - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        goodStr = string(2 * n, '.');
        result.clear();
        search(0, 0);
        return result;
    }
};