class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        stringstream s;
        for (int i = 1; i <= n; i++) {
            if (i % 3 != 0 && i % 5 != 0) {
                s << i;
            }
            if (i % 3 == 0) {
                s << "Fizz";
            }
            if (i % 5 == 0) {
                s << "Buzz";
            }
            res.push_back(s.str());
            s.str("");
        }
        return res;
    }
};