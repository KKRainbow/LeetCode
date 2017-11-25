class Solution {
    map<int, vector<vector<string>>> cache;
public:
    vector<vector<string>> partition(string s) {
        cache.clear();
        return partitionH(s);
    }
    
    vector<vector<string>> partitionH(const string& s, int leftBound = 0) {
        if (cache.find(leftBound) != cache.end()) {
            return cache[leftBound];
        }
        vector<vector<string>> res;
        int rightBound = s.length();
        int left = leftBound, right = s.length();
        while (rightBound > leftBound) {
            if (s[left] == s[right - 1]) {
                right--;
                left++; 
                if (right <= left) {
                    //good one
                    auto ares = partitionH(s, rightBound);
                    for (auto& v : ares) {
                        v.insert(v.begin(), s.substr(leftBound, rightBound - leftBound));
                        res.push_back(v);
                    }
                    if (ares.size() == 0) {
                        res.push_back({s.substr(leftBound, rightBound - leftBound)});
                    }
                    rightBound--;
                    left = leftBound;
                    right = rightBound;
                }
            } else {
                rightBound--;
                left = leftBound;
                right = rightBound;
            }
        }
        cache[leftBound] = res;
        return res;
    }
};