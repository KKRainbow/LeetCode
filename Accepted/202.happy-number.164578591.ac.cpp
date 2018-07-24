class Solution {
    int next(int n)
    {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        while (true)
        {
            auto y = next(n);
            if (y == 1) return true;
            if (s.find(y) != s.end()) return false;
            else
            {
                s.insert(y);
                n = y;
            }
        }
    }
};
