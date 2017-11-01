class Solution {
    string getRes(char c) {
        return c == 'R' ? "Radiant" : "Dire";
    }
public:
    string predictPartyVictory(string senate, int br = 0, int bd = 0) {
        string next;
        bool flag = false;
        for (auto c : senate) {
            if (c == 'R') {
                if (br > 0) {
                    br--;
                } else {
                    bd++;
                    next.push_back(c);
                }
            } else {
                if (bd > 0) {
                    bd--;
                } else {
                    br++;
                    next.push_back(c);
                }
            }
            if (next.length() > 1 && next[next.length() - 1] != next[next.length() - 2]) {
                flag = true;
            }
        }
        if (flag) return predictPartyVictory(next, br, bd);
        else return getRes(next[0]);
    }
};