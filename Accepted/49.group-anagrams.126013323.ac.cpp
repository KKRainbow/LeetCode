class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> rmap;
        for (auto& str : strs) {
            auto tmp = str;
            sort(str.begin(), str.end());
            rmap[str].push_back(tmp);
        }
        vector<vector<string>> res;
        for (auto &v : rmap) {
            res.push_back(v.second);
        }
        return res;
    }
};