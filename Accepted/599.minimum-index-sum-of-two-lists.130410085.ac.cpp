class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        if (list1.size() > list2.size()) {
            list1.swap(list2);
        }
        map<string, int> hash;
        int idx = 0;
        for (auto &str : list1) {
            hash[str] = idx++;
        }
        idx = 0;
        int res = INT_MAX;
        vector<string> vec;
        for (auto& str: list2) {
            auto it = hash.find(str);
            if (it != hash.end()) {
                auto tmp = it->second + idx;
                if (tmp <= res) {
                    if (tmp < res) {
                        vec.clear();
                    }
                    res = tmp;
                    vec.push_back(str);
                } 
            }
            idx++;
        }
        return vec;
    }
};