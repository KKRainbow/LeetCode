class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0, tail = s.length() - 1;
        while (head < tail) {
            if (!isalnum(s[head])) {
                head++;
                continue;
            }
            if (!isalnum(s[tail])) {
                tail--;
                continue;
            }
            if (toupper(s[head]) != toupper(s[tail])) {
                return false;
            } else {
                head++;
                tail--;
            }
        }
        return true;
    }
};
